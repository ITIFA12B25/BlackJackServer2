#include "gamesession.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

#include "card.h"
#include "hand.h"

// ------------------------------------------------------------
// Konstruktor: eine Session pro Client-Verbindung
// - Signals verbinden (readyRead, disconnected)
// - Begrüßung an Client senden
// ------------------------------------------------------------
GameSession::GameSession(QTcpSocket* socket, GameManager* manager, QObject* parent)
    : QObject(parent), m_socket(socket), m_manager(manager)
{
    // Client sendet Daten -> readyRead wird ausgelöst
    connect(m_socket, &QTcpSocket::readyRead, this, &GameSession::onReadyRead);

    // Client trennt Verbindung -> disconnected wird ausgelöst
    connect(m_socket, &QTcpSocket::disconnected, this, &GameSession::onDisconnected);

    // Begrüßung: einfacher Hello-Text als JSON
    sendJson(QJsonObject{{"type","hello"},{"msg","connected"}});
}

// ------------------------------------------------------------
// Liest alle Zeilen vom Socket (Protokoll: 1 JSON pro Zeile)
// ------------------------------------------------------------
void GameSession::onReadyRead()
{
    // Protokoll: JSON pro Zeile
    while (m_socket->canReadLine()) {
        const QByteArray line = m_socket->readLine().trimmed();
        if (!line.isEmpty()) handleLine(line);
    }
}

// ------------------------------------------------------------
// Client hat Verbindung getrennt
// - Session aus Room entfernen
// - Socket/Session löschen (deleteLater)
// ------------------------------------------------------------
void GameSession::onDisconnected()
{
    qDebug() << "Client disconnected";

    // Session aus Room entfernen (damit Room-State sauber bleibt)
    if (m_manager) m_manager->leaveBySession(this);

    // Qt: Objekte später löschen (sicher im Event-Loop)
    m_socket->deleteLater();
    deleteLater();
}

// ------------------------------------------------------------
// Verarbeitet eine einzelne Zeile (muss gültiges JSON sein)
// ------------------------------------------------------------
void GameSession::handleLine(const QByteArray& line)
{
    const QJsonDocument doc = QJsonDocument::fromJson(line);
    if (!doc.isObject()) { sendError("invalid json"); return; }

    const QJsonObject msg = doc.object();

    // Jede Nachricht braucht "type"
    if (!msg.contains("type") || !msg.value("type").isString()) {
        sendError("missing type");
        return;
    }

    handleMessage(msg);
}

// ------------------------------------------------------------
// Haupt-Message-Handler: reagiert auf "type"
// Unterstützt:
// - list_rooms
// - create_room
// - join_room
// - leave_room
// - hit
// - stand
// - newround
// ------------------------------------------------------------
void GameSession::handleMessage(const QJsonObject& msg)
{
    const QString type = msg.value("type").toString();

    // ------------------------------------------------------------
    // list_rooms: liefert Room-Liste für JoinRoom UI
    // {"type":"list_rooms"}
    // ------------------------------------------------------------
    if (type == "list_rooms") {
        QJsonObject resp;
        resp["type"]  = "rooms_list";
        resp["rooms"] = m_manager->roomsToJson();
        sendJson(resp);
        return;
    }

    // ------------------------------------------------------------
    // create_room: Host erstellt Room
    // {"type":"create_room","name":"Ali"}
    // ------------------------------------------------------------
    if (type == "create_room") {
        const QString name = msg.value("name").toString().trimmed();
        if (name.isEmpty()) { sendError("missing name"); return; }

        // Name speichern (für CSV / State)
        m_playerName = name;

        // Room erstellen (Host = Spieler 0)
        const QString rid = m_manager->createRoom(this, name);
        m_roomId = rid;
        m_seat = 0;

        // Antwort an Host: room_created
        sendJson(QJsonObject{
            {"type","room_created"},
            {"roomId", rid},
            {"seat", m_seat},
            {"msg","waiting_for_player2"}
        });
        return;
    }

    // ------------------------------------------------------------
    // join_room: Spieler 1 tritt bei; Spiel startet
    // {"type":"join_room","roomId":"123456","name":"Sara"}
    // ------------------------------------------------------------
    if (type == "join_room") {
        const QString rid  = msg.value("roomId").toString().trimmed();
        const QString name = msg.value("name").toString().trimmed();

        if (rid.isEmpty())  { sendError("missing roomId"); return; }
        if (name.isEmpty()) { sendError("missing name"); return; }

        // Join versuchen (GameManager prüft room exist / full / etc.)
        QString err;
        if (!m_manager->joinRoom(rid, this, name, &err)) {
            sendError(err.isEmpty() ? "join failed" : err);
            return;
        }

        // Session-Infos setzen
        m_playerName = name;
        m_roomId = rid;
        m_seat = 1;

        RoomState* r = m_manager->room(rid);
        if (!r) { sendError("room not found"); return; }

        // Beide Clients informieren: Spiel startet
        broadcastToRoom(QJsonObject{{"type","room_ready"},{"roomId", rid},{"msg","game_start"}});

        // Start-State an beide senden
        broadcastState(*r);
        return;
    }

    // ------------------------------------------------------------
    // Ab hier: Kommandos nur, wenn der Client in einem Room ist
    // ------------------------------------------------------------
    if (m_roomId.isEmpty() || m_seat < 0) {
        sendError("not in room");
        return;
    }

    RoomState* r = m_manager->room(m_roomId);
    if (!r) { sendError("room not found"); return; }

    // ------------------------------------------------------------
    // leave_room: Room verlassen
    // ------------------------------------------------------------
    if (type == "leave_room") {
        // Aus Room entfernen
        m_manager->leaveBySession(this);

        // Session-Infos zurücksetzen
        m_roomId.clear();
        m_seat = -1;

        // Antwort an Client
        sendJson(QJsonObject{{"type","left_room"},{"msg","ok"}});
        return;
    }

    // ------------------------------------------------------------
    // Spielaktionen nur während Playing erlaubt
    // ------------------------------------------------------------
    if (r->phase != GamePhase::Playing) {
        sendError("game not active");
        return;
    }

    // ------------------------------------------------------------
    // hit: Karte ziehen
    // ------------------------------------------------------------
    if (type == "hit") {
        PlayerState& me = r->players[m_seat];

        // Wenn schon stand/bust, dann darf man nicht mehr ziehen
        if (me.stood) { sendError("already stood"); return; }

        // Neue Karte ziehen
        me.hand.cards.push_back(r->deck.draw());

        // State an alle senden
        broadcastState(*r);

        // Bust prüfen: >21 => Spieler ist fertig
        if (handValue(me.hand) > 21) {
            me.stood = true;
            r->currentTurn = 1 - m_seat; // Turn wechseln (bust), du bist darin
            broadcastState(*r);
            tryFinishIfAllDone(*r);
        }
        return;
    }

    // ------------------------------------------------------------
    // stand: Spieler beendet seinen Zug
    // ------------------------------------------------------------
    if (type == "stand") {
        PlayerState& me = r->players[m_seat];
        me.stood = true;
        r->currentTurn = 1 - m_seat; // Turn wechseln, du bist daran

        // State senden und prüfen, ob Spiel fertig ist
        broadcastState(*r);
        tryFinishIfAllDone(*r);
        return;
    }

    // ------------------------------------------------------------
    // newround: neue Runde starten (nur wenn Finished)
    // ------------------------------------------------------------
    if (type == "newround") {
        // Nur erlaubt, wenn Runde beendet ist
        if (r->phase != GamePhase::Finished) { sendError("round not finished"); return; }

        // Deck + Dealer reset
        r->deck.reset();
        r->dealer.cards.clear();

        // Spieler reset
        for (int i = 0; i < 2; ++i) {
            r->players[i].hand.cards.clear();
            r->players[i].stood = false;
        }

        // Startkarten neu geben
        r->players[0].hand.cards.push_back(r->deck.draw());
        r->players[0].hand.cards.push_back(r->deck.draw());

        r->players[1].hand.cards.push_back(r->deck.draw());
        r->players[1].hand.cards.push_back(r->deck.draw());

        r->dealer.cards.push_back(r->deck.draw());
        r->dealer.cards.push_back(r->deck.draw());

        // Phase wieder Playing
        r->phase = GamePhase::Playing;

        // Info + State senden
        broadcastToRoom(QJsonObject{{"type","newround"},{"msg","ok"}});
        broadcastState(*r);
        return;
    }

    // Wenn type nicht bekannt ist
    sendError("unknown command");
}

// ------------------------------------------------------------
// Sendet JSON an Client (eine Zeile)
// ------------------------------------------------------------
void GameSession::sendJson(const QJsonObject& obj)
{
    const QJsonDocument doc(obj);

    // Compact JSON + '\n' als Trennung
    m_socket->write(doc.toJson(QJsonDocument::Compact) + "\n");
    m_socket->flush();
}

// ------------------------------------------------------------
// Hilfsfunktion: Fehler an Client senden
// ------------------------------------------------------------
void GameSession::sendError(const QString& msg)
{
    sendJson(QJsonObject{{"type","error"},{"msg",msg}});
}

// ------------------------------------------------------------
// Broadcast: sendet an beide Sessions im Room
// ------------------------------------------------------------
void GameSession::broadcastToRoom(const QJsonObject& obj)
{
    RoomState* r = m_manager->room(m_roomId);
    if (!r) return;

    for (int i = 0; i < 2; ++i) {
        if (r->sessions[i]) {
            r->sessions[i]->sendJson(obj);
        }
    }
}

// ------------------------------------------------------------
// Broadcast State: sendet den aktuellen Spielzustand an beide Clients
// - Dealer erste Karte verdeckt während Playing
// - Bei Finished sind Dealer-Karten sichtbar
// ------------------------------------------------------------
void GameSession::broadcastState(RoomState& r)
{
    // Dealer-Karten: im Spiel erste Karte verdeckt
    QJsonArray dealerCards;
    for (int i = 0; i < r.dealer.cards.size(); ++i) {
        if (r.phase == GamePhase::Playing && i == 0) dealerCards.append("?");
        else dealerCards.append(cardToString(r.dealer.cards[i]));
    }

    // Helper: Hand -> JSON Array von Strings
    auto cardsToJson = [](const Hand& h){
        QJsonArray arr;
        for (const Card& c : h.cards) arr.append(cardToString(c));
        return arr;
    };

    // State Objekt bauen
    QJsonObject state;
    state["type"] = "state";
    state["roomId"] = r.roomId;

    // Phase als Text
    state["phase"] = (r.phase == GamePhase::Playing ? "playing" : "finished");
    state["currentTurn"] = r.currentTurn;

    // Dealer Infos
    state["dealerCards"] = dealerCards;
    // Dealer total nur zeigen, wenn Runde fertig ist
    state["dealerTotal"] = (r.phase == GamePhase::Playing ? -1 : handValue(r.dealer));

    // Player 0 Infos
    state["p0_name"]  = r.players[0].name;
    state["p0_cards"] = cardsToJson(r.players[0].hand);
    state["p0_total"] = handValue(r.players[0].hand);
    state["p0_stood"] = r.players[0].stood;

    // Player 1 Infos
    state["p1_name"]  = r.players[1].name;
    state["p1_cards"] = cardsToJson(r.players[1].hand);
    state["p1_total"] = handValue(r.players[1].hand);
    state["p1_stood"] = r.players[1].stood;

    // An beide Sessions senden
    for (int i = 0; i < 2; ++i) {
        if (r.sessions[i]) r.sessions[i]->sendJson(state);
    }
}

// ------------------------------------------------------------
// Ergebnis-Text für einen Spieler (vergleich Player vs Dealer)
// ------------------------------------------------------------
QString GameSession::outcomeFor(int p, int d) const
{
    if (p > 21) return "player_bust";
    if (d > 21) return "dealer_bust";
    if (p > d)  return "player_win";
    if (p < d)  return "dealer_win";
    return "push";
}

// ------------------------------------------------------------
// Prüft, ob beide Spieler fertig sind
// Wenn ja: Dealer spielt, Ergebnis wird gesendet, Spielphase = Finished
// ------------------------------------------------------------
void GameSession::tryFinishIfAllDone(RoomState& r)
{
    // Nur wenn beide Spieler fertig sind (stood == true)
    if (!(r.players[0].stood && r.players[1].stood))
        return;

    // Dealer zieht bis mindestens 17
    while (handValue(r.dealer) < 17) {
        r.dealer.cards.push_back(r.deck.draw());
    }

    // Phase beenden
    r.phase = GamePhase::Finished;

    const int dealerTotal = handValue(r.dealer);

    // Ergebnis für beide Spieler berechnen und senden
    for (int i = 0; i < 2; ++i) {
        const int playerTotal = handValue(r.players[i].hand);
        const QString out = outcomeFor(playerTotal, dealerTotal);

        // CSV speichern (Server-Log)
        m_manager->appendWinnerCsv(r.roomId, r.players[i].name, out, playerTotal, dealerTotal);

        // Ergebnis an jeweiligen Client senden
        if (r.sessions[i]) {
            r.sessions[i]->sendJson(QJsonObject{
                {"type","result"},
                {"roomId", r.roomId},
                {"you", i},
                {"outcome", out},
                {"playerTotal", playerTotal},
                {"dealerTotal", dealerTotal}
            });
        }
    }

    // Finalen State senden (Dealer-Karten jetzt sichtbar)
    broadcastState(r);
}
