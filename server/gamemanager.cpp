#include "gamemanager.h"

#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "gamesession.h"
#include <QJsonObject>
#include <QJsonArray>

// ------------------------------------------------------------
// Erzeugt eine neue zufällige Room-ID (6-stellig)
// ------------------------------------------------------------
QString GameManager::newId() const
{
    // 6-stellige zufällige ID
    const int n = QRandomGenerator::global()->bounded(100000, 999999);
    return QString::number(n);
}

// ------------------------------------------------------------
// Erstellt einen neuen Room und setzt den Creator als Spieler 0 (Host)
// ------------------------------------------------------------
QString GameManager::createRoom(GameSession* creatorSession, const QString& creatorName)
{
    // Eindeutige ID finden (solange probieren, bis sie nicht existiert)
    QString id;
    do { id = newId(); } while (m_rooms.contains(id));

    RoomState r;
    r.roomId = id;

    // Host ist Spieler 0
    r.players[0].name = creatorName;
    r.players[0].hand.cards.clear();
    r.players[0].stood = false;

    // Session vom Host speichern (damit man später an ihn senden kann)
    r.sessions[0] = creatorSession;
    r.sessions[1] = nullptr;

    // Dealer zurücksetzen
    r.dealer.cards.clear();

    // Start: wartet auf zweiten Spieler
    r.phase = GamePhase::WaitingForPlayers;

    // Room in Hash speichern
    m_rooms.insert(id, r);
    return id;
}

// ------------------------------------------------------------
// Spieler 1 tritt einem Room bei (wenn möglich)
// Wenn beide Spieler da sind -> Spiel startet (Deck reset + Karten geben)
// ------------------------------------------------------------
bool GameManager::joinRoom(const QString& roomId, GameSession* joinerSession, const QString& joinerName, QString* errorOut)
{
    // Room muss existieren
    if (!m_rooms.contains(roomId)) {
        if (errorOut) *errorOut = "room not found";
        return false;
    }

    RoomState& r = m_rooms[roomId];

    // Room muss einen Host haben
    if (!r.sessions[0]) {
        if (errorOut) *errorOut = "room has no host";
        return false;
    }

    // Maximal 2 Spieler
    if (r.sessions[1]) {
        if (errorOut) *errorOut = "room full";
        return false;
    }

    // Spieler 1 setzen
    r.players[1].name = joinerName;
    r.players[1].hand.cards.clear();
    r.players[1].stood = false;

    // Session vom Joiner speichern
    r.sessions[1] = joinerSession;

    // ---------------- Spielstart vorbereiten ----------------
    // Deck neu mischen / reset
    r.deck.reset();

    // Dealer-Hand leeren
    r.dealer.cards.clear();

    // Beide Spieler zurücksetzen (Hand + stood)
    for (int i = 0; i < 2; ++i) {
        r.players[i].hand.cards.clear();
        r.players[i].stood = false;
    }

    // ---------------- Startkarten ----------------
    // Jeder Spieler bekommt 2 Karten, Dealer bekommt 2 Karten
    r.players[0].hand.cards.push_back(r.deck.draw());
    r.players[0].hand.cards.push_back(r.deck.draw());

    r.players[1].hand.cards.push_back(r.deck.draw());
    r.players[1].hand.cards.push_back(r.deck.draw());

    r.dealer.cards.push_back(r.deck.draw());
    r.dealer.cards.push_back(r.deck.draw());

    // Phase auf Playing setzen
    r.phase = GamePhase::Playing;
    return true;
}

// ------------------------------------------------------------
// Liefert Pointer auf RoomState (oder nullptr wenn nicht existiert)
// ------------------------------------------------------------
RoomState* GameManager::room(const QString& roomId)
{
    if (!m_rooms.contains(roomId)) return nullptr;
    return &m_rooms[roomId];
}

// ------------------------------------------------------------
// Prüft, ob ein Room existiert
// ------------------------------------------------------------
bool GameManager::roomExists(const QString& roomId) const
{
    return m_rooms.contains(roomId);
}

// ------------------------------------------------------------
// Entfernt eine Session aus einem Room (z.B. wenn Client disconnectet)
// ------------------------------------------------------------
void GameManager::leaveBySession(GameSession* s)
{
    QString rid;
    int seat = -1;

    // Erst suchen: in welchem Room und auf welchem Seat ist diese Session?
    if (!findSeat(s, &rid, &seat)) return;

    RoomState& r = m_rooms[rid];

    // Sitzplatz leeren (Session + Spielerinfo zurücksetzen)
    r.sessions[seat] = nullptr;
    r.players[seat].name.clear();
    r.players[seat].hand.cards.clear();
    r.players[seat].stood = false;

    // Wenn beide weg sind: Room komplett löschen
    if (!r.sessions[0] && !r.sessions[1]) {
        m_rooms.remove(rid);
    } else {
        // Wenn jemand während dem Spiel geht: Spiel beenden
        r.phase = GamePhase::Finished;
    }
}

// ------------------------------------------------------------
// Sucht in allen Rooms nach einer Session und gibt roomId + seat zurück
// ------------------------------------------------------------
bool GameManager::findSeat(GameSession* s, QString* roomIdOut, int* seatOut) const
{
    // Kleine Datenmenge: lineare Suche reicht hier
    for (auto it = m_rooms.constBegin(); it != m_rooms.constEnd(); ++it) {
        const RoomState& r = it.value();

        // Es gibt genau 2 Sitzplätze (0 und 1)
        for (int i = 0; i < 2; ++i) {
            // QPointer kann nullptr werden, wenn QObject gelöscht wurde
            if (r.sessions[i] && r.sessions[i].data() == s) {
                if (roomIdOut) *roomIdOut = r.roomId;
                if (seatOut) *seatOut = i;
                return true;
            }
        }
    }
    return false;
}

// ------------------------------------------------------------
// Schreibt Ergebnis in winners.csv (append)
// Format: timestamp, roomId, playerName, outcome, playerTotal, dealerTotal
// ------------------------------------------------------------
void GameManager::appendWinnerCsv(const QString& roomId, const QString& playerName, const QString& outcome, int playerTotal, int dealerTotal)
{
    // Serverweite Gewinnerliste: winners.csv (append)
    QFile f("winners.csv");
    const bool exists = f.exists();

    // Datei öffnen zum Anhängen
    if (!f.open(QIODevice::Append | QIODevice::Text)) return;

    QTextStream out(&f);

    // Header nur beim ersten Mal schreiben
    if (!exists) {
        out << "timestamp,roomId,playerName,outcome,playerTotal,dealerTotal\n";
    }

    // Zeitstempel im ISO-Format
    const QString ts = QDateTime::currentDateTime().toString(Qt::ISODate);

    // Eine Zeile CSV schreiben
    out << ts << ","
        << roomId << ","
        << playerName << ","
        << outcome << ","
        << playerTotal << ","
        << dealerTotal << "\n";
}

// ------------------------------------------------------------
// Baut eine Room-Liste als JSON für den Client (JoinRoom Tabelle)
// ------------------------------------------------------------
QJsonArray GameManager::roomsToJson() const
{
    QJsonArray arr;

    // Alle Rooms durchgehen
    for (auto it = m_rooms.constBegin(); it != m_rooms.constEnd(); ++it) {
        const RoomState& r = it.value();

        // Anzahl Spieler berechnen (wie viele Sessions sind da)
        int players = 0;
        if (r.sessions[0]) players++;
        if (r.sessions[1]) players++;

        // Phase als Text für JSON
        QString phaseStr = "waiting";
        if (r.phase == GamePhase::Playing)  phaseStr = "playing";
        if (r.phase == GamePhase::Finished) phaseStr = "finished";

        // JSON-Objekt pro Room
        QJsonObject o;
        o["roomId"]  = r.roomId;
        o["host"]    = r.players[0].name;
        o["phase"]   = phaseStr;
        o["players"] = players;

        arr.append(o);
    }

    return arr;
}
