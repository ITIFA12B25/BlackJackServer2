#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

#include "gamemanager.h"
#include "gamesession.h"

int main(int argc, char *argv[])
{
    // Qt Console-App starten (Event-Loop läuft am Ende mit a.exec())
    QCoreApplication a(argc, argv);

    // TCP Server-Objekt (nimmt Verbindungen an)
    QTcpServer server;

    // Zentrale Spiellogik / Room-Verwaltung
    GameManager manager;

    // Port für die Verbindung (Client muss den gleichen Port nutzen)
    const quint16 port = 4242;

    // ------------------------------------------------------------
    // Server starten (Console-App).
    // Lauscht auf allen Netzwerkkarten (Any) und dem Port
    // -------------------------------------------------------------
    if (!server.listen(QHostAddress::Any, port)) {
        // Wenn Listen nicht geht: Fehler ausgeben und Programm beenden
        qDebug() << "Listen failed:" << server.errorString();
        return 1;
    }

    // Info in der Konsole, dass Server läuft
    qDebug() << "Server listening on port" << port;

    // ------------------------------------------------------------
    // Neue Clients akzeptieren
    // newConnection wird ausgelöst, wenn ein Client connectet
    // ------------------------------------------------------------
    QObject::connect(&server, &QTcpServer::newConnection, [&](){
        // Mehrere Clients können gleichzeitig warten (pending)
        while (server.hasPendingConnections()) {
            // Nächsten Client-Socket holen
            QTcpSocket* sock = server.nextPendingConnection();
            qDebug() << "New client connected";

            // Für jeden Client eine eigene Session erzeugen
            // Session verbindet readyRead/disconnected intern
            new GameSession(sock, &manager, &a);
        }
    });

    // Event-Loop starten (Server läuft solange, bis Programm beendet wird)
    return a.exec();
}
