#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QString>

#include "gamemanager.h"

class GameSession : public QObject
{
    Q_OBJECT

public:
    // Repräsentiert eine Client-Verbindung (eine Session pro Client)
    explicit GameSession(QTcpSocket* socket, GameManager* manager, QObject* parent = nullptr);

    // Sendet ein JSON-Objekt als eine Zeile an den Client
    void sendJson(const QJsonObject& obj);

private slots:
    // Wird aufgerufen, wenn Daten vom Client ankommen
    void onReadyRead();

    // Wird aufgerufen, wenn der Client die Verbindung trennt
    void onDisconnected();

private:
    QTcpSocket*  m_socket  = nullptr; // TCP-Verbindung zum Client
    GameManager* m_manager = nullptr; // Referenz auf den GameManager

    // Room-Infos dieser Session
    QString m_roomId;       // ID vom Room, in dem der Client ist
    int m_seat = -1;        // Sitzplatz (0 oder 1), -1 = noch keiner
    QString m_playerName;   // Name des Spielers

    // Verarbeitet eine einzelne Zeile (JSON-String)
    void handleLine(const QByteArray& line);

    // Verarbeitet eine geparste JSON-Nachricht
    void handleMessage(const QJsonObject& msg);

    // Sendet eine Fehlermeldung an den Client
    void sendError(const QString& msg);

    // Broadcast: Nachricht an beide Clients im selben Room
    void broadcastToRoom(const QJsonObject& obj);

    // Sendet den gemeinsamen Spielzustand an alle Spieler im Room
    void broadcastState(RoomState& r);

    // Prüft, ob alle Spieler fertig sind, dann Dealer spielen lassen
    void tryFinishIfAllDone(RoomState& r);

    // Ermittelt das Spieler-Ergebnis (win/lose/push)
    QString outcomeFor(int playerTotal, int dealerTotal) const;
};

#endif // GAMESESSION_H
