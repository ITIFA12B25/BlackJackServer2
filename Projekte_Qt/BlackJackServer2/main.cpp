#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include "gamesession.h"
int main(int argc, char *argv[])
{
    // Startet eine Qt-Konsolenanwendung.
    // Notwendig, damit der Event-Loop für Netzwerk funktioniert.
    QCoreApplication a(argc, argv);

    // TCP-Server-Objekt erstellen
    QTcpServer server;

    // Zentrale Verwaltung aller Spiele (GameId -> Spielzustand)
    GameManager manager;

    // Wird ausgelöst, wenn ein neuer Client eine Verbindung aufbaut
    QObject::connect(&server, &QTcpServer::newConnection, [&]() {

        // Alle wartenden Verbindungen nacheinander abarbeiten
        while (server.hasPendingConnections()) {

            // Verbindung (Socket) vom Client übernehmen
            QTcpSocket* socket = server.nextPendingConnection();
            qDebug() << "Client connected";

            // Für jeden Client eine eigene Session erstellen
            // Die Session verarbeitet später alle Nachrichten dieses Clients
            new GameSession(socket, &manager, &server);
        }
    });

    // Portnummer festlegen
    const quint16 port = 4242;

    // Server starten und auf Verbindungen warten
    if (!server.listen(QHostAddress::Any, port)) {
        // Fehlerfall: Port belegt oder keine Berechtigung
        qDebug() << "Listen failed:" << server.errorString();
        return 1;
    }

    qDebug() << "Server listening on port" << port;

    // Startet den Qt-Event-Loop
    return a.exec();
    }
