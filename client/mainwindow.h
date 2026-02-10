#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QJsonObject>
#include <QAbstractSocket>
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QLabel;
class QLineEdit;
class QTableWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Hauptfenster: UI + Netzwerk initialisieren
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // Debug: protokolliert, wenn Widgets enabled/disabled werden
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    // Socket-Events (Verbindungszustand)
    void onConnected();                                      // Verbindung aufgebaut
    void onReadyRead();                                      // Daten vom Server angekommen
    void onErrorOccurred(QAbstractSocket::SocketError);       // Netzwerkfehler

    // Spiel-Aktionen (Buttons)
    void onHitClicked();                                     // Karte ziehen
    void onStandClicked();                                   // stehen bleiben
    void onNewRoundClicked();                                // neue Runde starten

    // Verbindung getrennt (Server/Client Disconnect)
    void onDisconnected();

private:
    Ui::MainWindow *ui;

    // TCP-Verbindung zum Server (Client-Socket)
    QTcpSocket m_socket;

    // Raum/Seat-Infos (z.B. Lobby/Room-System)
    QString m_roomId;        // aktuelle Room-ID (falls benutzt)
    int     m_seat = -1;     // Sitzplatz 0/1 (oder -1 = keiner)
    QString m_playerName;    // Name vom Spieler (z.B. aus Eingabe)

    // Join-Seite: welche Room-ID ist ausgewählt
    QString m_selectedRoomId;

    // JSON senden und Server-Nachrichten verarbeiten
    void sendJson(const QJsonObject& obj);
    void handleServerMessage(const QJsonObject& obj);

    // Debug: EventFilter auf Widgets installieren (enabled/disabled beobachten)
    void installEnabledWatcher(QWidget *root);

    // Seitenwechsel / UI-Zustände
    void enterLobby();
    void enterJoinRoom();
    void enterGameSimple();
    void enterGameTable();

    // Join-Seite zurücksetzen (z.B. Auswahl löschen, Button deaktivieren)
    void resetJoinUi();

    // UI anhand vom Server-State aktualisieren
    void updateGameSimpleFromState(const QJsonObject& state);
    void updateGameTableFromState(const QJsonObject& state);

    // Sicherer Zugriff: Widget kann fehlen -> nullptr möglich
    QLabel*        lbl(const char* objectName) const;
    QLineEdit*     edit(const char* objectName) const;
    QTableWidget*  tbl(const char* objectName) const;

    // Verbindungstext im UI setzen (z.B. "connected"/"disconnected")
    void setConnectionText(const QString& text);
};

#endif // MAINWINDOW_H
