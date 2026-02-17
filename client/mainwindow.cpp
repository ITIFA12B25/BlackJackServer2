#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QAbstractItemView>

// ------------------------------------------------------------
// Hilfsfunktion:
// Zweck: Manche Widgets werden (z.B. durch stackedWidget) deaktiviert.
// Hinweis: Danach Buttons/Controls gezielt per UI-State setzen.
// ------------------------------------------------------------
static void forceEnableAll(QWidget* root)
{
    if (!root) return;

    // Parents bis zum Top-Widget aktivieren
    QWidget* p = root;
    while (p) {
        p->setEnabled(true);
        p = p->parentWidget();
    }

    // Root + alle Children aktivieren
    root->setEnabled(true);
    const auto children = root->findChildren<QWidget*>();
    for (QWidget* w : children)
        w->setEnabled(true);
}

// ------------------------------------------------------------
// Karten-Resource:
// - Key "AH" -> Pfad zur PNG in Qt-Resources
// - Key "?"  -> back.png (verdeckte Karte)
// ------------------------------------------------------------

// Wandelt Karten-Key (z.B. "AH") in Resource-Pfad um
static QString cardKeyToResourcePath(const QString& key)
{
    // Verdeckte Karte (z.B. Dealer zweite Karte)
    if (key.isEmpty() || key == "?") {
        // Variante 1: Projektstruktur ":/cards/assets/cards/back.png"
        const QString p2 = ":/cards/assets/cards/back.png";
        if (QFile::exists(p2)) return p2;

        // Variante 2: ältere Struktur ":/cards/back.png"
        const QString p1 = ":/cards/back.png";
        if (QFile::exists(p1)) return p1;

        return QString(); // nicht gefunden
    }

    // Variante 1: ":/cards/AH.png"
    const QString p1 = QString(":/cards/%1.png").arg(key);
    if (QFile::exists(p1)) return p1;

    // Variante 2: ":/cards/assets/cards/AH.png"
    const QString p2 = QString(":/cards/assets/cards/%1.png").arg(key);
    if (QFile::exists(p2)) return p2;

    return QString(); // nicht gefunden
}

// Setzt ein Kartenbild in ein QLabel (skaliert, Seitenverhältnis bleibt)
// Wenn Bild nicht existiert: Text "NO IMG"
static void setCardLabel(QLabel* label, const QString& key, const QSize& targetSize)
{
    if (!label) return;

    const QString path = cardKeyToResourcePath(key);
    if (path.isEmpty()) {
        label->setText("NO IMG");
        label->setPixmap(QPixmap());
        return;
    }

    QPixmap px(path);
    if (px.isNull()) {
        label->setText("NO IMG");
        label->setPixmap(QPixmap());
        return;
    }

    label->setText("");
    label->setPixmap(px.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

// Leert eine Kartenanzeige (Text + Pixmap)
static void clearCardLabel(QLabel* label)
{
    if (!label) return;
    label->clear();
    label->setPixmap(QPixmap());
}

// ------------------------------------------------------------
// Debug: Enabled/Disabled Watcher (EventFilter)
// Zweck: finden, warum Widgets deaktiviert werden
// ------------------------------------------------------------
void MainWindow::installEnabledWatcher(QWidget *root)
{
    if (!root) return;

    // Root überwachen
    root->installEventFilter(this);

    // Alle Child-Widgets ebenfalls überwachen
    const auto children = root->findChildren<QWidget*>();
    for (QWidget *w : children)
        w->installEventFilter(this);
}

// Reagiert auf EnabledChange-Events und schreibt ins Debug-Log
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::EnabledChange) {
        if (auto *w = qobject_cast<QWidget*>(watched)) {
            qDebug().noquote()
            << "[EnabledChange]"
            << (w->isEnabled() ? "ENABLED" : "DISABLED")
            << "objectName=" << w->objectName();
        }
    }
    return QMainWindow::eventFilter(watched, event);
}

// ------------------------------------------------------------
// Safe Widget Zugriff
// Hinweis: findChild sucht im ganzen MainWindow; kann nullptr zurückgeben.
// ------------------------------------------------------------
QLabel* MainWindow::lbl(const char* objectName) const
{
    return this->findChild<QLabel*>(objectName);
}

QLineEdit* MainWindow::edit(const char* objectName) const
{
    return this->findChild<QLineEdit*>(objectName);
}

QTableWidget* MainWindow::tbl(const char* objectName) const
{
    return this->findChild<QTableWidget*>(objectName);
}
// ------------------------------------------------------------
// Reset: Spiel-UI sauber machen
// Zweck: Nach Leave/Back sollen alte Karten/Labels weg sein.
// ------------------------------------------------------------
void MainWindow::resetGameUi()
{
    // Texte leeren
    if (QLabel* w = lbl("lblWinner"))  w->clear();
    if (QLabel* s = lbl("status"))     s->clear();
    if (QLabel* st = lbl("lblStatus")) st->clear();

    if (QLabel* r = lbl("lblRoomInfo"))    r->clear();
    if (QLabel* r2 = lbl("lblRoomInfo_2")) r2->clear();

    if (QLabel* op = lbl("lblOppName")) op->clear();

    if (QLabel* dt = lbl("lblDealerTotal")) dt->clear();
    if (QLabel* pt = lbl("lblPlayerTotal")) pt->clear();
    if (QLabel* ot = lbl("lblOppTotal"))    ot->clear();

    // Karten leeren (Pixmaps)
    clearCardLabel(lbl("lblDealerCard1"));
    clearCardLabel(lbl("lblDealerCard2"));
    clearCardLabel(lbl("lblDealerCard3"));
    clearCardLabel(lbl("lblDealerCard4"));

    clearCardLabel(lbl("lblPlayerCard1"));
    clearCardLabel(lbl("lblPlayerCard2"));
    clearCardLabel(lbl("lblPlayerCard3"));
    clearCardLabel(lbl("lblPlayerCard4"));

    clearCardLabel(lbl("lblOppCard1"));
    clearCardLabel(lbl("lblOppCard2"));
    clearCardLabel(lbl("lblOppCard3"));
    clearCardLabel(lbl("lblOppCard4"));

    // Tabelle leeren
    if (ui->tableWidget) {
        ui->tableWidget->clearContents();
    }
}
// ------------------------------------------------------------
// Konstruktor: UI initialisieren, Signals/Slots verbinden, Socket starten
// ------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Debug-Watcher aktivieren (nur zum Testen)
    installEnabledWatcher(ui->centralwidget);

    // Sicherstellen, dass UI nicht global disabled bleibt
    this->setEnabled(true);
    forceEnableAll(ui->centralwidget);

    // Join-Tabelle: ganze Zeile auswählen (nicht einzelne Zelle)
    ui->tblRooms->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblRooms->setSelectionMode(QAbstractItemView::SingleSelection);

    // Startseite: Lobby
    enterLobby();

    // ---------------- Navigation (Seitenwechsel) ----------------
    connect(ui->btnGoJoin, &QPushButton::clicked, this, [this]{
        enterJoinRoom();
    });

    connect(ui->btnBackFromJoin, &QPushButton::clicked, this, [this]{
        enterLobby();
    });

    // ---------------- Create Room ----------------
    // Hinweis: Server bekommt "create_room" + player name
    connect(ui->btnGoCreate, &QPushButton::clicked, this, [this]{
        QLineEdit* nameEdit = edit("txtName");
        const QString name = nameEdit ? nameEdit->text().trimmed() : QString();

        m_playerName = name.isEmpty() ? "Player" : name;

        // Achtung: sendJson schreibt direkt auf Socket (wenn noch nicht verbunden,
        // puffert Qt i.d.R., aber sauberer wäre: erst connectToHost, dann senden)
        sendJson(QJsonObject{
            {"type","create_room"},
            {"name", m_playerName}
        });

        // Socket-Signale (Verbindung / Daten / Fehler)
        connect(&m_socket, &QTcpSocket::connected,
                this, &MainWindow::onConnected);

        connect(&m_socket, &QTcpSocket::disconnected,
                this, &MainWindow::onDisconnected);

        connect(&m_socket, &QTcpSocket::readyRead,
                this, &MainWindow::onReadyRead);

        connect(&m_socket, &QTcpSocket::errorOccurred,
                this, &MainWindow::onErrorOccurred);

        // State-Text "Connected/Disconnected" live anzeigen
        connect(&m_socket, &QTcpSocket::stateChanged, this,
                [this](QAbstractSocket::SocketState st){
                    if (st == QAbstractSocket::ConnectedState) setConnectionText("Connected");
                    else setConnectionText("Disconnected");
                });

    });

    // ---------------- JoinRoom Auswahl ----------------
    // Wenn eine Zeile ausgewählt ist, wird der Join-Button aktiviert.
    connect(ui->tblRooms, &QTableWidget::itemSelectionChanged, this, [this]{
        const auto ranges = ui->tblRooms->selectedRanges();
        if (ranges.isEmpty()) {
            m_selectedRoomId.clear();
            ui->join_room->setEnabled(false);
            return;
        }

        const int row = ranges.first().topRow();
        QTableWidgetItem* it = ui->tblRooms->item(row, 0); // RoomId in Spalte 0
        if (!it) {
            m_selectedRoomId.clear();
            ui->join_room->setEnabled(false);
            return;
        }

        m_selectedRoomId = it->text().trimmed();
        ui->join_room->setEnabled(!m_selectedRoomId.isEmpty());
    });

    // Join Button (objectName: join_room)
    connect(ui->join_room, &QPushButton::clicked, this, [this]{
        if (m_selectedRoomId.isEmpty()) return;

        QLineEdit* nameEdit = edit("txtName");
        const QString name = nameEdit ? nameEdit->text().trimmed() : QString();

        m_playerName = name.isEmpty() ? "Player" : name;

        // join_room Nachricht an Server
        sendJson(QJsonObject{
            {"type","join_room"},
            {"roomId", m_selectedRoomId},
            {"name", m_playerName}
        });
    });

    // Refresh (optional): Server soll Liste der Rooms schicken
    connect(ui->Refresh, &QPushButton::clicked, this, [this]{
        sendJson(QJsonObject{{"type","list_rooms"}});
    });

    // ---------------- Switch Views (Simple <-> Table) ----------------
    connect(ui->btnSwitchToTable, &QPushButton::clicked, this, [this]{
        enterGameTable();
    });

    connect(ui->btnSwitchToSimple, &QPushButton::clicked, this, [this]{
        enterGameSimple();
    });

    // ---------------- Leave Game ----------------
    // leave_room an Server und zurück zur Lobby
    connect(ui->btnLeaveGame1, &QPushButton::clicked, this, [this]{
        sendJson(QJsonObject{{"type","leave_room"}});
        m_roomId.clear();
        m_seat = -1;
        enterLobby();
    });

    connect(ui->btnLeaveGame2, &QPushButton::clicked, this, [this]{
        sendJson(QJsonObject{{"type","leave_room"}});
        m_roomId.clear();
        m_seat = -1;
        enterLobby();
    });

    // ---------------- Game Actions ----------------
    // Buttons existieren auf beiden Seiten (Simple + Table)
    connect(ui->btnHit,   &QPushButton::clicked, this, &MainWindow::onHitClicked);
    connect(ui->btnStand, &QPushButton::clicked, this, &MainWindow::onStandClicked);

    connect(ui->btnHit2,   &QPushButton::clicked, this, &MainWindow::onHitClicked);
    connect(ui->btnStand2, &QPushButton::clicked, this, &MainWindow::onStandClicked);


    // ---------------- Socket (global) ----------------
    // Diese connects gelten immer, egal ob Join oder Create
    connect(&m_socket, &QTcpSocket::connected,     this, &MainWindow::onConnected);
    connect(&m_socket, &QTcpSocket::readyRead,     this, &MainWindow::onReadyRead);
    connect(&m_socket, &QTcpSocket::errorOccurred, this, &MainWindow::onErrorOccurred);

    // Verbindung zum lokalen Server (Port 4242)
    m_socket.connectToHost("127.0.0.1", 4242);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ------------------------------------------------------------
// UI States (Seiten + Buttons korrekt setzen)
// ------------------------------------------------------------
void MainWindow::setConnectionText(const QString& text)
{
    // Label kann auf pageLobby liegen; findChild sucht im ganzen MainWindow
    if (QLabel* c = lbl("connection")) {
        c->setText(text);
    } else {
        // Wenn es nicht gefunden wird, stimmt objectName im Designer nicht
        qDebug() << "Connection label not found (objectName must be 'connection')";
    }
}

void MainWindow::enterLobby()
{
    // Wenn wir in Lobby gehen, altes Spiel komplett löschen
    resetGameUi();

    ui->stackedWidget->setCurrentWidget(ui->pageLobby);
    forceEnableAll(ui->pageLobby);

    setConnectionText(m_socket.state() == QAbstractSocket::ConnectedState ? "Connected" : "Disconnected");
}

void MainWindow::resetJoinUi()
{
    // Join-Button nur aktiv, wenn Room ausgewählt ist
    ui->tblRooms->clearSelection();
    m_selectedRoomId.clear();
    ui->join_room->setEnabled(false);
}

void MainWindow::enterJoinRoom()
{
    ui->stackedWidget->setCurrentWidget(ui->pageJoinRoom);
    forceEnableAll(ui->pageJoinRoom);
    resetJoinUi();
}

void MainWindow::enterGameSimple()
{
    ui->stackedWidget->setCurrentWidget(ui->pageGameSimple);
    forceEnableAll(ui->pageGameSimple);

    // Simple-Buttons aktivieren
    ui->btnHit->setEnabled(true);
    ui->btnStand->setEnabled(true);
    ui->btnSwitchToTable->setEnabled(true);
    ui->btnLeaveGame1->setEnabled(true);

}

void MainWindow::enterGameTable()
{
    ui->stackedWidget->setCurrentWidget(ui->pageGameTable);
    forceEnableAll(ui->pageGameTable);

    // Table-Buttons aktivieren
    ui->btnHit2->setEnabled(true);
    ui->btnStand2->setEnabled(true);
    ui->btnSwitchToSimple->setEnabled(true);
    ui->btnLeaveGame2->setEnabled(true);

    // Tabelle initialisieren (falls existiert)
    if (ui->tableWidget) {
        ui->tableWidget->setRowCount(3);
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setHorizontalHeaderLabels({"Player","Cards","Total","Stood"});
        ui->tableWidget->setVerticalHeaderLabels({"Dealer","You","Opp"});
    }
}

// ------------------------------------------------------------
// Netzwerk / JSON (Client -> Server)
// ------------------------------------------------------------
void MainWindow::sendJson(const QJsonObject& obj)
{
    // JSON compact + '\n' als Message-Delimiter
    const QJsonDocument doc(obj);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    data.append('\n');

    m_socket.write(data);
    m_socket.flush();
}

void MainWindow::onConnected()
{
    setConnectionText("Connected");
    qDebug() << "Connected";
}

void MainWindow::onDisconnected()
{
    // Verbindung getrennt (Server down / Client getrennt)
    setConnectionText("Disconnected");
    qDebug() << "Disconnected";
}

void MainWindow::onReadyRead()
{
    // Pro Nachricht eine Zeile (wie im Server implementiert)
    while (m_socket.canReadLine()) {
        const QByteArray line = m_socket.readLine().trimmed();
        if (line.isEmpty()) continue;

        const QJsonDocument doc = QJsonDocument::fromJson(line);
        if (!doc.isObject()) continue;

        handleServerMessage(doc.object());
    }
}

void MainWindow::onErrorOccurred(QAbstractSocket::SocketError)
{
    // Fehler: Status auf disconnected setzen und Debug-Text ausgeben
    setConnectionText("Disconnected");
    qDebug() << "Socket error:" << m_socket.errorString();
}

// ------------------------------------------------------------
// Server Messages (Model A): room_created / room_ready / state / result / error / rooms_list
// ------------------------------------------------------------
void MainWindow::handleServerMessage(const QJsonObject& obj)
{
    const QString type = obj.value("type").toString();
    // ------------------------------------------------------------
    // Gegner-Name anzeigen
    // - Wenn leer -> "Player"
    // ------------------------------------------------------------

    if (type == "room_created") {
        // Server hat Room erstellt und Sitzplatz vergeben
        m_roomId = obj.value("roomId").toString();
        m_seat   = obj.value("seat").toInt();

        // Room-ID in beiden Views anzeigen (falls Labels existieren)
        if (QLabel* r = lbl("lblRoomInfo"))   r->setText("ROOM ID: " + m_roomId);
        if (QLabel* r2 = lbl("lblRoomInfo_2")) r2->setText("ROOM ID: " + m_roomId);

        // In Game wechseln
        enterGameSimple();

        // Status-Text für Player2 warten
        if (QLabel* s = lbl("status")) s->setText("Waiting for Player2...");
        return;
    }

    if (type == "room_ready") {
        // Zwei Spieler sind da -> Spiel startet
        enterGameSimple();
        const QString rid = obj.value("roomId").toString();
        if (QLabel* r = lbl("lblRoomInfo"))    r->setText("ROOM ID: " + rid);
        if (QLabel* r2 = lbl("lblRoomInfo_2")) r2->setText("ROOM ID: " + rid);
        if (QLabel* s = lbl("status")) s->setText("Game started!");
        return;
    }

    if (type == "state") {

        // Room-ID anzeigen
        QString rid = obj.value("roomId").toString();
        if (QLabel* r  = lbl("lblRoomInfo"))    r->setText("ROOM ID: " + rid);
        if (QLabel* r2 = lbl("lblRoomInfo_2"))  r2->setText("ROOM ID: " + rid);

        // Sitzplatz (nur einmal setzen)
        if (m_seat < 0 && obj.contains("you"))
            m_seat = obj.value("you").toInt(-1);

        // Karten/Points updaten
        updateGameSimpleFromState(obj);
        updateGameTableFromState(obj);

        // -------- Buttons an/aus (sehr einfach) --------

        // Phase lesen (playing / finished)
        QString phase = obj.value("phase").toString();

        // Turn lesen (0/1)
        int currentTurn = obj.value("currentTurn").toInt(-1);

        // Wenn Spiel finished -> immer AUS
        bool myTurn = false;
        if (phase != "finished") {
            // Nur wenn du dran bist -> AN
            myTurn = (currentTurn == m_seat);
        }

        // Buttons setzen
        ui->btnHit->setEnabled(myTurn);
        ui->btnStand->setEnabled(myTurn);
        ui->btnHit2->setEnabled(myTurn);
        ui->btnStand2->setEnabled(myTurn);

        // Status-Text
        if (QLabel* s = lbl("status"))
            s->setText(myTurn ? "Your turn" : "Opponent turn");

        // -------- Opp-Name nur als Name --------
        QString p0 = obj.value("p0_name").toString().trimmed();
        QString p1 = obj.value("p1_name").toString().trimmed();
        if (p0.isEmpty()) p0 = "Player";
        if (p1.isEmpty()) p1 = "Player";

        QString oppName = (m_seat == 0 ? p1 : p0);
        if (QLabel* o = lbl("lblOppName"))
            o->setText(oppName);

        return;

    }

    if (type == "result") {

        // Einfache Regeln:
        // - you_win  -> "You win!"
        // - you_lose -> "You lost!" + "X wins!"
        // - draw     -> "Draw!" + "You = Dealer/Opp"

        const QString outcome = obj.value("outcome").toString();
        const int youSeat = obj.value("you").toInt(m_seat);

        // Namen lesen (leer -> Player)
        QString p0Name = obj.value("p0_name").toString().trimmed();
        QString p1Name = obj.value("p1_name").toString().trimmed();
        if (p0Name.isEmpty()) p0Name = "Player";
        if (p1Name.isEmpty()) p1Name = "Player";

        // Gegner-Name
        const QString oppName = (youSeat == 0 ? p1Name : p0Name);

        // Gewinner-Name (Server)
        QString winnerName = obj.value("winner_name").toString().trimmed();

        // Optional: Draw mit Dealer
        const bool drawWithDealer = obj.value("draw_with_dealer").toBool(false);

        QString text;

        if (outcome == "you_win") {
            text = "You win!";
        }
        else if (outcome == "you_lose") {

            // Falls Server keinen Gewinner schickt -> Dealer als Default
            if (winnerName.isEmpty())
                winnerName = "Dealer";

            text = "You lost!\n" + winnerName + " wins!";
        }
        else if (outcome == "draw") {

            // Mit wem war es gleich?
            const QString partner = drawWithDealer ? "Dealer" : oppName;

            text = "Draw!\nYou = " + partner;
        }
        else {
            text = "Round finished!";
        }

        if (QLabel* w = lbl("lblWinner"))
            w->setText(text);

        return;
    }

    if (type == "error") {
        // Server meldet Fehler (z.B. join first, no game, etc.)
        qDebug() << "Server error:" << obj.value("msg").toString();
        if (QLabel* s = lbl("status")) s->setText("Error: " + obj.value("msg").toString());
        return;
    }

    if (type == "rooms_list") {
        // Liste der verfügbaren Rooms für Join-Seite
        const QJsonArray rooms = obj.value("rooms").toArray();

        // Tabelle vorbereiten
        ui->tblRooms->clearContents();
        ui->tblRooms->setRowCount(rooms.size());
        ui->tblRooms->setColumnCount(4);
        ui->tblRooms->setHorizontalHeaderLabels({"RoomId","Host","Phase","Players"});

        // Daten pro Zeile eintragen
        for (int row = 0; row < rooms.size(); ++row) {
            const QJsonObject r = rooms[row].toObject();

            const QString roomId  = r.value("roomId").toString();
            const QString host    = r.value("host").toString();
            const QString phase   = r.value("phase").toString();
            const int players     = r.value("players").toInt();

            ui->tblRooms->setItem(row, 0, new QTableWidgetItem(roomId));
            ui->tblRooms->setItem(row, 1, new QTableWidgetItem(host));
            ui->tblRooms->setItem(row, 2, new QTableWidgetItem(phase));
            ui->tblRooms->setItem(row, 3, new QTableWidgetItem(QString("%1/2").arg(players)));
        }

        // Join erst nach Auswahl erlauben
        m_selectedRoomId.clear();
        ui->join_room->setEnabled(false);
        return;
    }

}

// ------------------------------------------------------------
// Game Actions (Client -> Server)
// ------------------------------------------------------------
void MainWindow::onHitClicked()
{
    // Spieler zieht eine Karte
    sendJson(QJsonObject{{"type","hit"}});
}
void MainWindow::onStandClicked()
{
    // Spieler bleibt stehen
    sendJson(QJsonObject{{"type","stand"}});
}


// ------------------------------------------------------------
// UI Update: GameSimple (Bilder)
// Totals optional:
// - lblDealerTotal, lblPlayerTotal, lblOppTotal
// ------------------------------------------------------------
void MainWindow::updateGameSimpleFromState(const QJsonObject& state)
{
    // Arrays aus dem Server-State
    const QJsonArray dealer = state.value("dealerCards").toArray();
    const QJsonArray p0     = state.value("p0_cards").toArray();
    const QJsonArray p1     = state.value("p1_cards").toArray();

    // "you" und "opp" hängen vom seat ab
    const QJsonArray you = (m_seat == 1 ? p1 : p0);
    const QJsonArray opp = (m_seat == 1 ? p0 : p1);

    // Zielgröße für Bilder (UI-Design)
    const QSize dealerSize(72, 108);
    const QSize playerSize(72, 108);
    const QSize oppSize(72, 108);

    // Labels holen (kann nullptr sein, wenn objectName nicht existiert)
    QLabel* d1 = lbl("lblDealerCard1");
    QLabel* d2 = lbl("lblDealerCard2");
    QLabel* d3 = lbl("lblDealerCard3");
    QLabel* d4 = lbl("lblDealerCard4");

    QLabel* pA = lbl("lblPlayerCard1");
    QLabel* pB = lbl("lblPlayerCard2");
    QLabel* pC = lbl("lblPlayerCard3");
    QLabel* pD = lbl("lblPlayerCard4");
    QLabel* pE = lbl("lblPlayerCard5");
    QLabel* pF = lbl("lblPlayerCard6");

    QLabel* o1 = lbl("lblOppCard1");
    QLabel* o2 = lbl("lblOppCard2");
    QLabel* o3 = lbl("lblOppCard3");
    QLabel* o4 = lbl("lblOppCard4");
    QLabel* o5 = lbl("lblOppCard5");
    QLabel* o6 = lbl("lblOppCard6");

    // Dealer-Karten setzen (oder leeren)
    if (dealer.size() > 0) setCardLabel(d1, dealer[0].toString(), dealerSize); else clearCardLabel(d1);
    if (dealer.size() > 1) setCardLabel(d2, dealer[1].toString(), dealerSize); else clearCardLabel(d2);
    if (dealer.size() > 2) setCardLabel(d3, dealer[2].toString(), dealerSize); else clearCardLabel(d3);
    if (dealer.size() > 3) setCardLabel(d4, dealer[3].toString(), dealerSize); else clearCardLabel(d4);
    // Spieler-Karten
    if (you.size() > 0) setCardLabel(pA, you[0].toString(), playerSize); else clearCardLabel(pA);
    if (you.size() > 1) setCardLabel(pB, you[1].toString(), playerSize); else clearCardLabel(pB);
    if (you.size() > 2) setCardLabel(pC, you[2].toString(), playerSize); else clearCardLabel(pC);
    if (you.size() > 3) setCardLabel(pD, you[3].toString(), playerSize); else clearCardLabel(pD);
    if (you.size() > 4) setCardLabel(pE, you[4].toString(), playerSize); else clearCardLabel(pE);
    if (you.size() > 5) setCardLabel(pF, you[5].toString(), playerSize); else clearCardLabel(pF);
    // Gegner-Karten
    if (opp.size() > 0) setCardLabel(o1, opp[0].toString(), oppSize); else clearCardLabel(o1);
    if (opp.size() > 1) setCardLabel(o2, opp[1].toString(), oppSize); else clearCardLabel(o2);
    if (opp.size() > 2) setCardLabel(o3, opp[2].toString(), oppSize); else clearCardLabel(o3);
    if (opp.size() > 3) setCardLabel(o4, opp[3].toString(), oppSize); else clearCardLabel(o4);
    if (opp.size() > 4) setCardLabel(o5, opp[4].toString(), oppSize); else clearCardLabel(o5);
    if (opp.size() > 5) setCardLabel(o6, opp[5].toString(), oppSize); else clearCardLabel(o6);


    // Totals + Phase
    const QString phase = state.value("phase").toString();
    const int dealerTotal = state.value("dealerTotal").toInt();

    if (QLabel* dt = lbl("lblDealerTotal")) {
        if (dealerTotal < 0) dt->setText("Dealer: ?");
        else dt->setText(QString("Dealer: %1").arg(dealerTotal));
    }

    const int youTotal = (m_seat == 1 ? state.value("p1_total").toInt() : state.value("p0_total").toInt());
    const int oppTotal = (m_seat == 1 ? state.value("p0_total").toInt() : state.value("p1_total").toInt());

    if (QLabel* pt = lbl("lblPlayerTotal")) pt->setText(QString("Total: %1").arg(youTotal));
    if (QLabel* ot = lbl("lblOppTotal"))    ot->setText(QString("Total: %1").arg(oppTotal));

    // Dealer-Total in "playing" verstecken (z.B. zweite Karte verdeckt)
    if (QLabel* dt = lbl("lblDealerTotal")) {
        if (phase == "playing") dt->setText("Dealer: ?");
        else dt->setText(QString("Dealer: %1").arg(dealerTotal));
    }
    const int turn = state.value("currentTurn").toInt(-1);

    if (QLabel* st = lbl("lblStatus")) {
        if (state.value("phase").toString() != "playing") {
            st->setText("Round finished");
        } else if (turn == m_seat) {
            st->setText("Your turn");
        } else {
            st->setText("Waiting for opponent...");
        }
    }
    // ---------- Opponent Name anzeigen ----------
    // Gegnername aus state holen
    QString p0name = state.value("p0_name").toString().trimmed();
    QString p1name = state.value("p1_name").toString().trimmed();

    // Gegner bestimmen (anderer Seat)
    QString oppName;
    if (m_seat == 0)
        oppName = p1name;
    else
        oppName = p0name;

    // Falls kein Name eingegeben wurde -> "Player"
    if (oppName.isEmpty())
        oppName = "Player";

    // Nur Name anzeigen
    if (QLabel* l = lbl("lblOppName"))
        l->setText(oppName);
}

// ------------------------------------------------------------
// UI Update: GameTable (Text)
// Erwartete Widgets:
// - tableWidget (QTableWidget)
// - lblRoomInfo_2 (optional)
// - status (optional)
// ------------------------------------------------------------
void MainWindow::updateGameTableFromState(const QJsonObject& state)
{
    // Wenn tableWidget nicht existiert (z.B. UI anders), einfach raus
    if (!ui->tableWidget) return;

    const QString phase = state.value("phase").toString();

    // Karten aus dem State
    const QJsonArray dealer = state.value("dealerCards").toArray();
    const QJsonArray p0     = state.value("p0_cards").toArray();
    const QJsonArray p1     = state.value("p1_cards").toArray();

    // Namen/Status aus dem State
    const QString p0name = state.value("p0_name").toString();
    const QString p1name = state.value("p1_name").toString();

    const bool p0stood = state.value("p0_stood").toBool();
    const bool p1stood = state.value("p1_stood").toBool();

    // Totals aus dem State
    const int dealerTotal = state.value("dealerTotal").toInt();
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(dealerTotal < 0 ? "?" : QString::number(dealerTotal)));


    const int p0Total     = state.value("p0_total").toInt();
    const int p1Total     = state.value("p1_total").toInt();

    // Helper: QJsonArray -> "AH, 10S, ..."
    auto joinCards = [](const QJsonArray& arr){
        QStringList list;
        for (const auto& v : arr) list << v.toString();
        return list.join(", ");
    };

    const QString dealerCards = joinCards(dealer);
    const QString p0Cards     = joinCards(p0);
    const QString p1Cards     = joinCards(p1);

    // Row 0: Dealer
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Dealer"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(dealerCards));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(phase == "playing" ? "?" : QString::number(dealerTotal)));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem("-"));

    // Row 1: Player 0
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem(p0name.isEmpty() ? "Player0" : p0name));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem(p0Cards));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem(QString::number(p0Total)));
    ui->tableWidget->setItem(1, 3, new QTableWidgetItem(p0stood ? "true" : "false"));

    // Row 2: Player 1
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem(p1name.isEmpty() ? "Player1" : p1name));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem(p1Cards));
    ui->tableWidget->setItem(2, 2, new QTableWidgetItem(QString::number(p1Total)));
    ui->tableWidget->setItem(2, 3, new QTableWidgetItem(p1stood ? "true" : "false"));
}
