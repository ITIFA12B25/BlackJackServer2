#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <QObject>
#include<QTcpSocket>
#include<QString>
#include<QJsonObject>
#include"gamemanager.h"

// Diese Klasse repräsentiert eine Spiel-Session für einen Client
//bekommt den Socket des Clients

class GameSession : public QObject
{
public:
    // Socket + GameManager übernehmen
    explicit GameSession(QTcpSocket* socket, GameManager* manager, QObject *parent = nullptr);

private:
     // Netzwerk
    QTcpSocket* m_socket;
        GameManager* m_manager;
    // Merkt sich, in welchem Spiel der Client ist
    QString m_gameId;

    // Hilfsfunktionen
    void handleLine(const QByteArray& line);
    void handleMessage(const QString& type, const QString& gameIdFromMsg);

    void sendJson(const QJsonObject& obj);
    void sendError(const QString& msg);

private slots:
    // Wenn Daten ankommen
    void onReadyRead();
    // Wenn Client trennt
    void onDisconnected();
};

#endif // GAMESESSION_H
