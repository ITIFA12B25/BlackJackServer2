#include "gamesession.h"
#include<QJsonObject>
#include<QJsonDocument>
#include<QRandomGenerator>

GameSession::GameSession(QTcpSocket* socket, GameManager* manager, QObject *parent)
    : QObject(parent), m_socket(socket), m_manager(manager)
{
    // Wird aufgerufen, wenn der Client Daten sendet
    connect(m_socket, &QTcpSocket::readyRead,
            this, &GameSession::onReadyRead);

    // Wird aufgerufen, wenn der Client die Verbindung trennt
    connect(m_socket, &QTcpSocket::disconnected,
            this, &GameSession::onDisconnected);

    // Optionale Begrüßungsnachricht
    sendJson(QJsonObject{
        {"type","hello"},
        {"msg","connected"}
    });
}

void GameSession::onReadyRead()
{
    // Nachrichten werden zeilenweise gelesen (jede Nachricht endet mit '\n')
    while (m_socket->canReadLine()) {
        QByteArray line = m_socket->readLine().trimmed();
        if (!line.isEmpty())
            handleLine(line);
    }
}

void GameSession::handleLine(const QByteArray& line)
{
    // JSON-Nachricht vom Client parsen
    QJsonDocument doc = QJsonDocument::fromJson(line);

    // Ungültiges JSON -> Fehler zurücksenden
    if (!doc.isObject()) {
        sendError("invalid json");
        return;
    }

    QJsonObject obj = doc.object();

    // Nachrichtentyp auslesen (z.B. create, join, hit, stand)
    const QString type = obj.value("type").toString();

    // optionale GameId (z.B. beim join)
    const QString gameId = obj.value("gameId").toString();

    if (type.isEmpty()) {
        sendError("missing type");
        return;
    }

    // Nachricht auswerten
    handleMessage(type, gameId);
}

void GameSession::handleMessage(const QString& type, const QString& gameIdFromMsg)
{
    // -------- Spiel erstellen --------
    if (type == "create") {
        m_gameId = m_manager->createGame();

        sendJson(QJsonObject{
            {"type","created"},
            {"gameId",m_gameId}
        });
        return;
    }

    // -------- Spiel beitreten --------
    if (type == "join") {
        if (gameIdFromMsg.isEmpty()) {
            sendError("missing gameId");
            return;
        }

        if (!m_manager->exists(gameIdFromMsg)) {
            sendError("game not found");
            return;
        }

        m_gameId = gameIdFromMsg;

        sendJson(QJsonObject{
            {"type","joined"},
            {"gameId",m_gameId}
        });
        return;
    }

    // Ab hier: Spieler muss in einem Spiel sein
    if (m_gameId.isEmpty()) {
        sendError("no active game");
        return;
    }

    GameState* state = m_manager->state(m_gameId);
    if (!state || state->finished) {
        sendError("game finished or invalid");
        return;
    }

    // -------- Hit --------
    if (type == "hit") {
        // Prototyp: zufälliger Kartenwert
        state->playerTotal += QRandomGenerator::global()->bounded(1, 12);

        if (state->playerTotal > 21)
            state->finished = true;

        sendJson(QJsonObject{
            {"type","state"},
            {"playerTotal",state->playerTotal}
        });
        return;
    }

    // -------- Stand --------
    if (type == "stand") {
        state->finished = true;

        sendJson(QJsonObject{
            {"type","result"},
            {"outcome","finished"}
        });
        return;
    }

    // Unbekannter Befehl
    sendError("unknown command");
}

void GameSession::sendJson(const QJsonObject& obj)
{
    // JSON-Objekt in Bytes umwandeln und senden
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    data.append('\n');
    m_socket->write(data);
}

void GameSession::sendError(const QString& msg)
{
    // Einheitliches Fehlerformat
    sendJson(QJsonObject{
        {"type","error"},
        {"msg",msg}
    });
}

void GameSession::onDisconnected()
{
    // Speicher freigeben, wenn Client disconnectet
    m_socket->deleteLater();
    deleteLater();
}
