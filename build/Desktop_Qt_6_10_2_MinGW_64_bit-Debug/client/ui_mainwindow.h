/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pageCreateRoom;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *CreateRoomBox;
    QGridLayout *gridLayout_5;
    QLabel *balanceEdit;
    QLineEdit *editBalance;
    QLabel *label_2;
    QSpinBox *spinPlayers;
    QPushButton *btnCreateRoom;
    QPushButton *btnBackFromCreate;
    QWidget *pageGameSimple;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QLabel *lblRoomInfo;
    QLabel *lblStatus;
    QGroupBox *groupBox_player1;
    QGridLayout *gridLayout_3;
    QLabel *YOU;
    QLabel *lblPlayerTotal;
    QLabel *lblWinner;
    QGroupBox *groupBox_player2;
    QGridLayout *gridLayout_4;
    QLabel *lblOppName;
    QLabel *lblOppTotal;
    QLabel *lblPlayerCard1;
    QLabel *lblPlayerCard2;
    QLabel *lblPlayerCard3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QLabel *YOU_2;
    QLabel *lblDealerCard1;
    QLabel *lblDealerCard2;
    QLabel *lblDealerCard3;
    QLabel *lblDealerCard4;
    QLabel *lblDealerTotal;
    QLabel *lblOppCard1;
    QLabel *lblOppCard2;
    QLabel *lblOppCard3;
    QLabel *lblPlayerCard4;
    QLabel *lblPlayerCard5;
    QLabel *lblPlayerCard6;
    QLabel *lblOppCard4;
    QLabel *lblOppCard5;
    QLabel *lblOppCard6;
    QPushButton *btnSwitchToTable;
    QPushButton *btnHit;
    QPushButton *btnStand;
    QPushButton *btnLeaveGame1;
    QWidget *pageGameTable;
    QGridLayout *gridLayout_2;
    QLabel *lblRoomInfo_2;
    QTableWidget *tableWidget;
    QPushButton *btnStand2;
    QPushButton *btnHit2;
    QPushButton *btnSwitchToSimple;
    QPushButton *btnLeaveGame2;
    QWidget *pageJoinRoom;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTableWidget *tblRooms;
    QPushButton *join_room;
    QPushButton *btnBackFromJoin;
    QPushButton *Refresh;
    QWidget *pageLobby;
    QGridLayout *gridLayout;
    QLabel *connection;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *txtName;
    QPushButton *btnGoCreate;
    QPushButton *btnGoJoin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(false);
        MainWindow->resize(899, 614);
        QFont font;
        font.setPointSize(8);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QWidget#centralwidget {\n"
"    background-image: url(:/test/assets/Medien.jpeg);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"/*   background-color: #0b3d2e;*/\n"
"}\n"
""));
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("/* =========================\n"
"   Hintergrund f\303\274r gesamte Anwendung\n"
"   ========================= */\n"
"QWidget#centralwidget {\n"
"    border-image: url(\":/test/assets/Medien.jpeg\") 0 0 0 0 stretch stretch;\n"
"\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: rgba(0, 0, 0, 80);\n"
"    color: rgb(31, 35, 31);\n"
"    border: 2px solid rgb(31, 35, 31);\n"
"    border-radius: 14px;\n"
"    padding: 10px 18px;\n"
"}\n"
"\n"
"\n"
"/* Hover-Effekt */\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 0, 0, 110);\n"
"}\n"
"\n"
"/* Klick-Effekt */\n"
"QPushButton:pressed {\n"
"    background-color: rgba(0, 0, 0, 140);\n"
"}\n"
"\n"
"/* Deaktivierter Zustand */\n"
"QPushButton:disabled {\n"
"    background-color: rgba(0, 0, 0, 40);\n"
"    color: rgba(31, 35, 31,120);\n"
"    border: 2px solid rgba(0, 0, 0, 120);\n"
"}\n"
""));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(false);
        stackedWidget->setGeometry(QRect(9, 9, 881, 542));
        stackedWidget->setStyleSheet(QString::fromUtf8("QStackedWidget#stackedWidget { background: transparent; }"));
        pageCreateRoom = new QWidget();
        pageCreateRoom->setObjectName("pageCreateRoom");
        pageCreateRoom->setStyleSheet(QString::fromUtf8("/* Jede Page im StackedWidget transparent machen */\n"
"QWidget#pageLobby {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QWidget#pageGameSimple {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QWidget#pageGameTable {\n"
"    background: transparent;\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(pageCreateRoom);
        verticalLayout_2->setObjectName("verticalLayout_2");
        CreateRoomBox = new QGroupBox(pageCreateRoom);
        CreateRoomBox->setObjectName("CreateRoomBox");
        CreateRoomBox->setEnabled(false);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font1.setPointSize(24);
        font1.setBold(true);
        CreateRoomBox->setFont(font1);
        CreateRoomBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        CreateRoomBox->setCheckable(false);
        gridLayout_5 = new QGridLayout(CreateRoomBox);
        gridLayout_5->setObjectName("gridLayout_5");
        balanceEdit = new QLabel(CreateRoomBox);
        balanceEdit->setObjectName("balanceEdit");
        balanceEdit->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(balanceEdit->sizePolicy().hasHeightForWidth());
        balanceEdit->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font2.setPointSize(17);
        font2.setBold(true);
        balanceEdit->setFont(font2);
        balanceEdit->setScaledContents(false);

        gridLayout_5->addWidget(balanceEdit, 0, 0, 1, 1);

        editBalance = new QLineEdit(CreateRoomBox);
        editBalance->setObjectName("editBalance");
        editBalance->setEnabled(false);
        editBalance->setFont(font2);

        gridLayout_5->addWidget(editBalance, 1, 0, 1, 1);

        label_2 = new QLabel(CreateRoomBox);
        label_2->setObjectName("label_2");
        label_2->setEnabled(false);
        label_2->setFont(font2);

        gridLayout_5->addWidget(label_2, 2, 0, 1, 1);

        spinPlayers = new QSpinBox(CreateRoomBox);
        spinPlayers->setObjectName("spinPlayers");
        spinPlayers->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinPlayers->sizePolicy().hasHeightForWidth());
        spinPlayers->setSizePolicy(sizePolicy1);
        spinPlayers->setFont(font2);
        spinPlayers->setMinimum(1);
        spinPlayers->setMaximum(4);

        gridLayout_5->addWidget(spinPlayers, 3, 0, 1, 1);

        btnCreateRoom = new QPushButton(CreateRoomBox);
        btnCreateRoom->setObjectName("btnCreateRoom");
        btnCreateRoom->setEnabled(false);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font3.setPointSize(18);
        font3.setBold(true);
        btnCreateRoom->setFont(font3);
        btnCreateRoom->setIconSize(QSize(30, 30));

        gridLayout_5->addWidget(btnCreateRoom, 4, 0, 1, 1);

        btnBackFromCreate = new QPushButton(CreateRoomBox);
        btnBackFromCreate->setObjectName("btnBackFromCreate");
        btnBackFromCreate->setEnabled(false);
        btnBackFromCreate->setFont(font3);

        gridLayout_5->addWidget(btnBackFromCreate, 5, 0, 1, 1);


        verticalLayout_2->addWidget(CreateRoomBox);

        stackedWidget->addWidget(pageCreateRoom);
        pageGameSimple = new QWidget();
        pageGameSimple->setObjectName("pageGameSimple");
        pageGameSimple->setStyleSheet(QString::fromUtf8("QWidget#pageGameSimple { background: transparent; }"));
        groupBox = new QGroupBox(pageGameSimple);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 20, 819, 471));
        groupBox->setMinimumSize(QSize(741, 200));
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8("    background: transparent;\n"
"border :transparebt;\n"
""));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setObjectName("gridLayout_7");
        lblRoomInfo = new QLabel(groupBox);
        lblRoomInfo->setObjectName("lblRoomInfo");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblRoomInfo->sizePolicy().hasHeightForWidth());
        lblRoomInfo->setSizePolicy(sizePolicy2);
        lblRoomInfo->setMinimumSize(QSize(713, 25));
        lblRoomInfo->setMaximumSize(QSize(16777215, 500));
        lblRoomInfo->setFont(font2);
        lblRoomInfo->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"border-radius: 6px;"));
        lblRoomInfo->setTextFormat(Qt::TextFormat::AutoText);
        lblRoomInfo->setScaledContents(true);
        lblRoomInfo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lblRoomInfo, 0, 0, 1, 7);

        lblStatus = new QLabel(groupBox);
        lblStatus->setObjectName("lblStatus");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font4.setPointSize(8);
        lblStatus->setFont(font4);
        lblStatus->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"border-radius: 6px;"));

        gridLayout_7->addWidget(lblStatus, 1, 3, 1, 1);

        groupBox_player1 = new QGroupBox(groupBox);
        groupBox_player1->setObjectName("groupBox_player1");
        sizePolicy1.setHeightForWidth(groupBox_player1->sizePolicy().hasHeightForWidth());
        groupBox_player1->setSizePolicy(sizePolicy1);
        groupBox_player1->setMinimumSize(QSize(200, 100));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font5.setPointSize(13);
        groupBox_player1->setFont(font5);
        groupBox_player1->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"border-radius: 6px;\n"
" border: 2px solid rgba(0, 0, 0, 120);"));
        gridLayout_3 = new QGridLayout(groupBox_player1);
        gridLayout_3->setObjectName("gridLayout_3");
        YOU = new QLabel(groupBox_player1);
        YOU->setObjectName("YOU");
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font6.setPointSize(12);
        YOU->setFont(font6);
        YOU->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"border-radius: 6px;\n"
"border:transparent;"));

        gridLayout_3->addWidget(YOU, 0, 0, 1, 1);

        lblPlayerTotal = new QLabel(groupBox_player1);
        lblPlayerTotal->setObjectName("lblPlayerTotal");
        lblPlayerTotal->setFont(font4);
        lblPlayerTotal->setStyleSheet(QString::fromUtf8("    border: 2px solid rgba(0, 0, 0, 120);\n"
"border:transparent;"));

        gridLayout_3->addWidget(lblPlayerTotal, 1, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_player1, 2, 0, 1, 3);

        lblWinner = new QLabel(groupBox);
        lblWinner->setObjectName("lblWinner");
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font7.setPointSize(18);
        lblWinner->setFont(font7);
        lblWinner->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"\n"
"border:transparent;"));

        gridLayout_7->addWidget(lblWinner, 2, 3, 1, 1);

        groupBox_player2 = new QGroupBox(groupBox);
        groupBox_player2->setObjectName("groupBox_player2");
        sizePolicy1.setHeightForWidth(groupBox_player2->sizePolicy().hasHeightForWidth());
        groupBox_player2->setSizePolicy(sizePolicy1);
        groupBox_player2->setMinimumSize(QSize(200, 100));
        groupBox_player2->setFont(font5);
        groupBox_player2->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"border-radius: 6px;\n"
" border: 2px solid rgba(0, 0, 0, 120);"));
        gridLayout_4 = new QGridLayout(groupBox_player2);
        gridLayout_4->setObjectName("gridLayout_4");
        lblOppName = new QLabel(groupBox_player2);
        lblOppName->setObjectName("lblOppName");
        lblOppName->setFont(font6);
        lblOppName->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"border:transparent;"));

        gridLayout_4->addWidget(lblOppName, 0, 0, 1, 1);

        lblOppTotal = new QLabel(groupBox_player2);
        lblOppTotal->setObjectName("lblOppTotal");
        lblOppTotal->setFont(font4);
        lblOppTotal->setStyleSheet(QString::fromUtf8("border:transparent;"));

        gridLayout_4->addWidget(lblOppTotal, 1, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_player2, 2, 5, 1, 3);

        lblPlayerCard1 = new QLabel(groupBox);
        lblPlayerCard1->setObjectName("lblPlayerCard1");
        lblPlayerCard1->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblPlayerCard1, 3, 0, 1, 1);

        lblPlayerCard2 = new QLabel(groupBox);
        lblPlayerCard2->setObjectName("lblPlayerCard2");
        lblPlayerCard2->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblPlayerCard2, 3, 1, 1, 1);

        lblPlayerCard3 = new QLabel(groupBox);
        lblPlayerCard3->setObjectName("lblPlayerCard3");
        lblPlayerCard3->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblPlayerCard3, 3, 2, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(32);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setMinimumSize(QSize(280, 200));
        groupBox_2->setFont(font5);
        groupBox_2->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"border-radius: 6px;\n"
"border: 2px solid rgba(0, 0, 0, 120);"));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setObjectName("gridLayout_6");
        YOU_2 = new QLabel(groupBox_2);
        YOU_2->setObjectName("YOU_2");
        YOU_2->setFont(font6);
        YOU_2->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"border-radius: 6px;\n"
"border:transparent;"));

        gridLayout_6->addWidget(YOU_2, 0, 0, 1, 1);

        lblDealerCard1 = new QLabel(groupBox_2);
        lblDealerCard1->setObjectName("lblDealerCard1");
        lblDealerCard1->setMinimumSize(QSize(70, 105));
        lblDealerCard1->setStyleSheet(QString::fromUtf8("border:transparent;"));

        gridLayout_6->addWidget(lblDealerCard1, 1, 0, 1, 1);

        lblDealerCard2 = new QLabel(groupBox_2);
        lblDealerCard2->setObjectName("lblDealerCard2");
        lblDealerCard2->setMinimumSize(QSize(70, 105));
        lblDealerCard2->setStyleSheet(QString::fromUtf8("border:transparent;"));

        gridLayout_6->addWidget(lblDealerCard2, 1, 1, 1, 1);

        lblDealerCard3 = new QLabel(groupBox_2);
        lblDealerCard3->setObjectName("lblDealerCard3");
        lblDealerCard3->setMinimumSize(QSize(70, 105));
        lblDealerCard3->setStyleSheet(QString::fromUtf8("border:transparent;"));

        gridLayout_6->addWidget(lblDealerCard3, 1, 2, 1, 1);

        lblDealerCard4 = new QLabel(groupBox_2);
        lblDealerCard4->setObjectName("lblDealerCard4");
        lblDealerCard4->setMinimumSize(QSize(70, 105));
        lblDealerCard4->setStyleSheet(QString::fromUtf8("border:transparent;"));

        gridLayout_6->addWidget(lblDealerCard4, 1, 3, 1, 1);

        lblDealerTotal = new QLabel(groupBox_2);
        lblDealerTotal->setObjectName("lblDealerTotal");
        lblDealerTotal->setMinimumSize(QSize(0, 15));
        lblDealerTotal->setFont(font4);
        lblDealerTotal->setStyleSheet(QString::fromUtf8("border:transparent;"));

        gridLayout_6->addWidget(lblDealerTotal, 2, 0, 1, 2);

        lblDealerTotal->raise();
        lblDealerCard1->raise();
        lblDealerCard2->raise();
        lblDealerCard3->raise();
        lblDealerCard4->raise();
        YOU_2->raise();

        gridLayout_7->addWidget(groupBox_2, 3, 3, 2, 2);

        lblOppCard1 = new QLabel(groupBox);
        lblOppCard1->setObjectName("lblOppCard1");
        lblOppCard1->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblOppCard1, 3, 5, 1, 1);

        lblOppCard2 = new QLabel(groupBox);
        lblOppCard2->setObjectName("lblOppCard2");
        lblOppCard2->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblOppCard2, 3, 6, 1, 1);

        lblOppCard3 = new QLabel(groupBox);
        lblOppCard3->setObjectName("lblOppCard3");
        lblOppCard3->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblOppCard3, 3, 7, 1, 1);

        lblPlayerCard4 = new QLabel(groupBox);
        lblPlayerCard4->setObjectName("lblPlayerCard4");
        lblPlayerCard4->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblPlayerCard4, 4, 0, 1, 1);

        lblPlayerCard5 = new QLabel(groupBox);
        lblPlayerCard5->setObjectName("lblPlayerCard5");
        lblPlayerCard5->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblPlayerCard5, 4, 1, 1, 1);

        lblPlayerCard6 = new QLabel(groupBox);
        lblPlayerCard6->setObjectName("lblPlayerCard6");
        lblPlayerCard6->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblPlayerCard6, 4, 2, 1, 1);

        lblOppCard4 = new QLabel(groupBox);
        lblOppCard4->setObjectName("lblOppCard4");
        lblOppCard4->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblOppCard4, 4, 5, 1, 1);

        lblOppCard5 = new QLabel(groupBox);
        lblOppCard5->setObjectName("lblOppCard5");
        lblOppCard5->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblOppCard5, 4, 6, 1, 1);

        lblOppCard6 = new QLabel(groupBox);
        lblOppCard6->setObjectName("lblOppCard6");
        lblOppCard6->setMinimumSize(QSize(72, 108));

        gridLayout_7->addWidget(lblOppCard6, 4, 7, 1, 1);

        btnSwitchToTable = new QPushButton(groupBox);
        btnSwitchToTable->setObjectName("btnSwitchToTable");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnSwitchToTable->sizePolicy().hasHeightForWidth());
        btnSwitchToTable->setSizePolicy(sizePolicy4);
        btnSwitchToTable->setMinimumSize(QSize(0, 45));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font8.setPointSize(14);
        btnSwitchToTable->setFont(font8);
        btnSwitchToTable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 0, 0, 80);\n"
"    color: rgb(31, 35, 31);\n"
"    border: 2px solid rgb(31, 35, 31);\n"
"    border-radius: 14px;\n"
"    padding: 10px 18px;\n"
"}\n"
"\n"
"\n"
"/* Hover-Effekt */\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 0, 0, 110);\n"
"}\n"
"\n"
"/* Klick-Effekt */\n"
"QPushButton:pressed {\n"
"    background-color: rgba(0, 0, 0, 140);\n"
"}\n"
"\n"
"/* Deaktivierter Zustand */\n"
"QPushButton:disabled {\n"
"    background-color: rgba(0, 0, 0, 40);\n"
"    color: rgba(31, 35, 31,120);\n"
"    border: 2px solid rgba(0, 0, 0, 120);\n"
"}"));

        gridLayout_7->addWidget(btnSwitchToTable, 5, 0, 1, 2);

        btnHit = new QPushButton(groupBox);
        btnHit->setObjectName("btnHit");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btnHit->sizePolicy().hasHeightForWidth());
        btnHit->setSizePolicy(sizePolicy5);
        btnHit->setMinimumSize(QSize(0, 45));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font9.setPointSize(17);
        btnHit->setFont(font9);
        btnHit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 0, 0, 80);\n"
"    color: rgb(31, 35, 31);\n"
"    border: 2px solid rgb(31, 35, 31);\n"
"    border-radius: 14px;\n"
"    padding: 10px 18px;\n"
"}\n"
"\n"
"\n"
"/* Hover-Effekt */\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 0, 0, 110);\n"
"}\n"
"\n"
"/* Klick-Effekt */\n"
"QPushButton:pressed {\n"
"    background-color: rgba(0, 0, 0, 140);\n"
"}\n"
"\n"
"/* Deaktivierter Zustand */\n"
"QPushButton:disabled {\n"
"    background-color: rgba(0, 0, 0, 40);\n"
"    color: rgba(31, 35, 31,120);\n"
"    border: 2px solid rgba(0, 0, 0, 120);\n"
"}"));

        gridLayout_7->addWidget(btnHit, 5, 3, 1, 1);

        btnStand = new QPushButton(groupBox);
        btnStand->setObjectName("btnStand");
        sizePolicy5.setHeightForWidth(btnStand->sizePolicy().hasHeightForWidth());
        btnStand->setSizePolicy(sizePolicy5);
        btnStand->setMinimumSize(QSize(0, 45));
        btnStand->setFont(font7);
        btnStand->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        btnStand->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 0, 0, 80);\n"
"    color: rgb(31, 35, 31);\n"
"    border: 2px solid rgb(31, 35, 31);\n"
"    border-radius: 14px;\n"
"    padding: 10px 18px;\n"
"}\n"
"\n"
"\n"
"/* Hover-Effekt */\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 0, 0, 110);\n"
"}\n"
"\n"
"/* Klick-Effekt */\n"
"QPushButton:pressed {\n"
"    background-color: rgba(0, 0, 0, 140);\n"
"}\n"
"\n"
"/* Deaktivierter Zustand */\n"
"QPushButton:disabled {\n"
"    background-color: rgba(0, 0, 0, 40);\n"
"    color: rgba(31, 35, 31,120);\n"
"    border: 2px solid rgba(0, 0, 0, 120);\n"
"}"));

        gridLayout_7->addWidget(btnStand, 5, 4, 1, 1);

        btnLeaveGame1 = new QPushButton(groupBox);
        btnLeaveGame1->setObjectName("btnLeaveGame1");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(btnLeaveGame1->sizePolicy().hasHeightForWidth());
        btnLeaveGame1->setSizePolicy(sizePolicy6);
        btnLeaveGame1->setMinimumSize(QSize(0, 45));
        btnLeaveGame1->setFont(font8);
        btnLeaveGame1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 0, 0, 80);\n"
"    color: rgb(31, 35, 31);\n"
"    border: 2px solid rgb(31, 35, 31);\n"
"    border-radius: 14px;\n"
"    padding: 10px 18px;\n"
"}\n"
"\n"
"\n"
"/* Hover-Effekt */\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 0, 0, 110);\n"
"}\n"
"\n"
"/* Klick-Effekt */\n"
"QPushButton:pressed {\n"
"    background-color: rgba(0, 0, 0, 140);\n"
"}\n"
"\n"
"/* Deaktivierter Zustand */\n"
"QPushButton:disabled {\n"
"    background-color: rgba(0, 0, 0, 40);\n"
"    color: rgba(31, 35, 31,120);\n"
"    border: 2px solid rgba(0, 0, 0, 120);\n"
"}"));

        gridLayout_7->addWidget(btnLeaveGame1, 5, 6, 1, 2);

        lblRoomInfo->raise();
        lblStatus->raise();
        lblPlayerCard1->raise();
        lblPlayerCard2->raise();
        groupBox_2->raise();
        lblOppCard2->raise();
        lblOppCard1->raise();
        btnHit->raise();
        lblPlayerCard3->raise();
        lblPlayerCard4->raise();
        lblOppCard3->raise();
        lblOppCard4->raise();
        btnLeaveGame1->raise();
        groupBox_player2->raise();
        btnSwitchToTable->raise();
        groupBox_player1->raise();
        lblWinner->raise();
        lblOppCard5->raise();
        lblOppCard6->raise();
        lblPlayerCard5->raise();
        lblPlayerCard6->raise();
        btnStand->raise();
        stackedWidget->addWidget(pageGameSimple);
        pageGameTable = new QWidget();
        pageGameTable->setObjectName("pageGameTable");
        pageGameTable->setStyleSheet(QString::fromUtf8("QWidget#pageGameTable { background: transparent; }"));
        gridLayout_2 = new QGridLayout(pageGameTable);
        gridLayout_2->setObjectName("gridLayout_2");
        lblRoomInfo_2 = new QLabel(pageGameTable);
        lblRoomInfo_2->setObjectName("lblRoomInfo_2");
        sizePolicy2.setHeightForWidth(lblRoomInfo_2->sizePolicy().hasHeightForWidth());
        lblRoomInfo_2->setSizePolicy(sizePolicy2);
        lblRoomInfo_2->setMinimumSize(QSize(713, 50));
        lblRoomInfo_2->setMaximumSize(QSize(16777215, 500));
        lblRoomInfo_2->setFont(font2);
        lblRoomInfo_2->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"border-radius: 6px;"));
        lblRoomInfo_2->setTextFormat(Qt::TextFormat::AutoText);
        lblRoomInfo_2->setScaledContents(true);
        lblRoomInfo_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblRoomInfo_2, 0, 0, 1, 3);

        tableWidget = new QTableWidget(pageGameTable);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setFont(font6);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget, QTableView {\n"
"    background-color: rgba(31, 35, 31,60);    \n"
"    color: white;                            \n"
"    gridline-color: rgba(0,20,0,60);                   \n"
"    border: 2px solid rgba(0,20,0,60);                \n"
"    border-radius: 12px;                     \n"
"    selection-background-color: rgba(0, 20, 0,60);\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* Zellen */\n"
"QTableWidget::item, QTableView::item {\n"
"    padding: 8px;\n"
"    border: 1px solid rgba(0, 20, 0, 120);\n"
"	color: rgb(0, 20, 0);\n"
"}\n"
"\n"
"/* Header (Spalten\303\274berschriften) */\n"
"QHeaderView::section {\n"
"    background-color: rgba(0, 20, 0,40);     /* Header dunkler */\n"
"    color: white;\n"
"    border: 1px solid black;\n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"	font: 12pt \"Comic Sans MS\";\n"
"}\n"
"\n"
"/* Ecke links oben (bei QTableWidget) */\n"
"QTableCornerButton::section {\n"
"    background-color: rgba(31, 35, 31, 140);\n"
"    border: 1px solid black;\n"
"}\n"
""
                        "/*wnn selected nicht \303\244ndert*/\n"
"QTableWidget#tblRooms::item:selected {\n"
"    color: rgb(0, 20, 0);\n"
"}"));

        gridLayout_2->addWidget(tableWidget, 1, 0, 1, 3);

        btnStand2 = new QPushButton(pageGameTable);
        btnStand2->setObjectName("btnStand2");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(btnStand2->sizePolicy().hasHeightForWidth());
        btnStand2->setSizePolicy(sizePolicy7);
        btnStand2->setMinimumSize(QSize(0, 45));
        btnStand2->setMaximumSize(QSize(300, 100));
        btnStand2->setFont(font9);

        gridLayout_2->addWidget(btnStand2, 2, 0, 1, 1);

        btnHit2 = new QPushButton(pageGameTable);
        btnHit2->setObjectName("btnHit2");
        QSizePolicy sizePolicy8(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Ignored);
        sizePolicy8.setHorizontalStretch(10);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(btnHit2->sizePolicy().hasHeightForWidth());
        btnHit2->setSizePolicy(sizePolicy8);
        btnHit2->setMinimumSize(QSize(10, 0));
        btnHit2->setMaximumSize(QSize(300, 100));
        btnHit2->setFont(font9);

        gridLayout_2->addWidget(btnHit2, 3, 0, 1, 1);

        btnSwitchToSimple = new QPushButton(pageGameTable);
        btnSwitchToSimple->setObjectName("btnSwitchToSimple");
        btnSwitchToSimple->setMinimumSize(QSize(0, 45));
        btnSwitchToSimple->setMaximumSize(QSize(300, 16777215));
        btnSwitchToSimple->setFont(font9);

        gridLayout_2->addWidget(btnSwitchToSimple, 2, 2, 1, 1);

        btnLeaveGame2 = new QPushButton(pageGameTable);
        btnLeaveGame2->setObjectName("btnLeaveGame2");
        btnLeaveGame2->setMinimumSize(QSize(0, 45));
        btnLeaveGame2->setMaximumSize(QSize(300, 16777215));
        btnLeaveGame2->setFont(font9);

        gridLayout_2->addWidget(btnLeaveGame2, 3, 2, 1, 1);

        stackedWidget->addWidget(pageGameTable);
        pageJoinRoom = new QWidget();
        pageJoinRoom->setObjectName("pageJoinRoom");
        pageJoinRoom->setStyleSheet(QString::fromUtf8("QWidget#pageJoinRoom { background: transparent; }"));
        verticalLayout_3 = new QVBoxLayout(pageJoinRoom);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(pageJoinRoom);
        label_3->setObjectName("label_3");
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font10.setPointSize(26);
        font10.setWeight(QFont::ExtraBold);
        label_3->setFont(font10);
        label_3->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"border-radius: 6px;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        tblRooms = new QTableWidget(pageJoinRoom);
        if (tblRooms->columnCount() < 4)
            tblRooms->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font8);
        tblRooms->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font8);
        tblRooms->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font8);
        tblRooms->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblRooms->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        if (tblRooms->rowCount() < 3)
            tblRooms->setRowCount(3);
        tblRooms->setObjectName("tblRooms");
        tblRooms->setMaximumSize(QSize(16777215, 16777177));
        tblRooms->setFont(font6);
        tblRooms->setStyleSheet(QString::fromUtf8("\n"
"QTableWidget, QTableView {\n"
"    background-color: rgba(31, 35, 31,60);    \n"
"    color: white;                            \n"
"    gridline-color: rgba(0,20,0,60);                   \n"
"    border: 2px solid rgba(0,20,0,60);                \n"
"    border-radius: 12px;                     \n"
"    selection-background-color: rgba(0, 20, 0,60);\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* Zellen */\n"
"QTableWidget::item, QTableView::item {\n"
"    padding: 8px;\n"
"    border: 1px solid rgba(0, 20, 0, 120);\n"
"	color: rgb(0, 20, 0);\n"
"}\n"
"\n"
"/* Header (Spalten\303\274berschriften) */\n"
"QHeaderView::section {\n"
"    background-color: rgba(0, 20, 0,40);     /* Header dunkler */\n"
"    color: white;\n"
"    border: 1px solid black;\n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"	font: 12pt \"Comic Sans MS\";\n"
"}\n"
"\n"
"/* Ecke links oben (bei QTableWidget) */\n"
"QTableCornerButton::section {\n"
"    background-color: rgba(31, 35, 31, 140);\n"
"    border: 1px solid black;\n"
""
                        "}\n"
"/*wnn selected nicht \303\244ndert*/\n"
"QTableWidget#tblRooms::item:selected {\n"
"    color: rgb(0, 20, 0);\n"
"}\n"
"\n"
""));
        tblRooms->setFrameShape(QFrame::Shape::NoFrame);
        tblRooms->setFrameShadow(QFrame::Shadow::Plain);
        tblRooms->setLineWidth(9);
        tblRooms->setMidLineWidth(5);
        tblRooms->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        tblRooms->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        tblRooms->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        tblRooms->setAlternatingRowColors(false);
        tblRooms->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tblRooms->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tblRooms->setShowGrid(true);
        tblRooms->setGridStyle(Qt::PenStyle::SolidLine);
        tblRooms->setSortingEnabled(true);
        tblRooms->setWordWrap(true);
        tblRooms->setCornerButtonEnabled(false);
        tblRooms->setRowCount(3);
        tblRooms->setColumnCount(4);
        tblRooms->horizontalHeader()->setVisible(true);
        tblRooms->horizontalHeader()->setCascadingSectionResizes(true);
        tblRooms->horizontalHeader()->setMinimumSectionSize(60);
        tblRooms->horizontalHeader()->setDefaultSectionSize(142);
        tblRooms->horizontalHeader()->setHighlightSections(true);
        tblRooms->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tblRooms->horizontalHeader()->setStretchLastSection(true);
        tblRooms->verticalHeader()->setCascadingSectionResizes(true);
        tblRooms->verticalHeader()->setMinimumSectionSize(28);
        tblRooms->verticalHeader()->setDefaultSectionSize(79);
        tblRooms->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tblRooms->verticalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tblRooms);

        join_room = new QPushButton(pageJoinRoom);
        join_room->setObjectName("join_room");
        join_room->setEnabled(false);
        sizePolicy5.setHeightForWidth(join_room->sizePolicy().hasHeightForWidth());
        join_room->setSizePolicy(sizePolicy5);
        join_room->setMinimumSize(QSize(0, 50));
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font11.setPointSize(18);
        font11.setBold(false);
        join_room->setFont(font11);

        verticalLayout_3->addWidget(join_room);

        btnBackFromJoin = new QPushButton(pageJoinRoom);
        btnBackFromJoin->setObjectName("btnBackFromJoin");
        btnBackFromJoin->setEnabled(false);
        sizePolicy5.setHeightForWidth(btnBackFromJoin->sizePolicy().hasHeightForWidth());
        btnBackFromJoin->setSizePolicy(sizePolicy5);
        btnBackFromJoin->setMinimumSize(QSize(0, 50));
        btnBackFromJoin->setFont(font7);

        verticalLayout_3->addWidget(btnBackFromJoin);

        Refresh = new QPushButton(pageJoinRoom);
        Refresh->setObjectName("Refresh");
        Refresh->setEnabled(false);
        sizePolicy5.setHeightForWidth(Refresh->sizePolicy().hasHeightForWidth());
        Refresh->setSizePolicy(sizePolicy5);
        Refresh->setMinimumSize(QSize(0, 50));
        Refresh->setFont(font7);

        verticalLayout_3->addWidget(Refresh);

        stackedWidget->addWidget(pageJoinRoom);
        pageLobby = new QWidget();
        pageLobby->setObjectName("pageLobby");
        pageLobby->setStyleSheet(QString::fromUtf8("QWidget#pageLobby { background: transparent; }"));
        gridLayout = new QGridLayout(pageLobby);
        gridLayout->setObjectName("gridLayout");
        connection = new QLabel(pageLobby);
        connection->setObjectName("connection");
        connection->setMinimumSize(QSize(15, 15));
        connection->setStyleSheet(QString::fromUtf8("color: rgba(0,20,0,210);\n"
"border-radius: 6px;"));

        gridLayout->addWidget(connection, 0, 0, 1, 1);

        label = new QLabel(pageLobby);
        label->setObjectName("label");
        QSizePolicy sizePolicy9(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy9);
        label->setMinimumSize(QSize(4, 250));
        label->setSizeIncrement(QSize(5, 0));
        label->setBaseSize(QSize(0, 0));
        QFont font12;
        font12.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font12.setPointSize(58);
        font12.setBold(true);
        font12.setHintingPreference(QFont::PreferVerticalHinting);
        label->setFont(font12);
        label->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("    color: rgb(31, 35, 31);\n"
"\n"
""));
        label->setLineWidth(0);
        label->setTextFormat(Qt::TextFormat::PlainText);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 2, 3);

        label_5 = new QLabel(pageLobby);
        label_5->setObjectName("label_5");
        QFont font13;
        font13.setStyleStrategy(QFont::PreferDefault);
        font13.setHintingPreference(QFont::PreferNoHinting);
        label_5->setFont(font13);
        label_5->setMargin(100);

        gridLayout->addWidget(label_5, 1, 3, 2, 1);

        label_6 = new QLabel(pageLobby);
        label_6->setObjectName("label_6");
        QFont font14;
        font14.setHintingPreference(QFont::PreferNoHinting);
        label_6->setFont(font14);
        label_6->setMargin(93);

        gridLayout->addWidget(label_6, 2, 0, 3, 1);

        label_4 = new QLabel(pageLobby);
        label_4->setObjectName("label_4");
        QFont font15;
        font15.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font15.setPointSize(19);
        label_4->setFont(font15);
        label_4->setStyleSheet(QString::fromUtf8("\n"
"  /*  background-color: rgba(rgba(131, 255, 207, 90) 90);*/\n"
"    color: rgb(31, 35, 31);\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
""));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        txtName = new QLineEdit(pageLobby);
        txtName->setObjectName("txtName");
        sizePolicy5.setHeightForWidth(txtName->sizePolicy().hasHeightForWidth());
        txtName->setSizePolicy(sizePolicy5);
        txtName->setMinimumSize(QSize(0, 67));
        QFont font16;
        font16.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font16.setPointSize(19);
        font16.setHintingPreference(QFont::PreferNoHinting);
        txtName->setFont(font16);
        txtName->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgba(0, 0, 0, 80);\n"
"color: rgb(31, 35, 31);\n"
"border: 2px solid rgb(31, 35, 31);\n"
"border-radius: 14px;\n"
"padding: 10px 18px;\n"
""));

        gridLayout->addWidget(txtName, 2, 2, 1, 1);

        btnGoCreate = new QPushButton(pageLobby);
        btnGoCreate->setObjectName("btnGoCreate");
        btnGoCreate->setEnabled(false);
        QSizePolicy sizePolicy10(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(btnGoCreate->sizePolicy().hasHeightForWidth());
        btnGoCreate->setSizePolicy(sizePolicy10);
        btnGoCreate->setMinimumSize(QSize(0, 71));
        btnGoCreate->setFont(font15);

        gridLayout->addWidget(btnGoCreate, 3, 1, 1, 2);

        btnGoJoin = new QPushButton(pageLobby);
        btnGoJoin->setObjectName("btnGoJoin");
        sizePolicy10.setHeightForWidth(btnGoJoin->sizePolicy().hasHeightForWidth());
        btnGoJoin->setSizePolicy(sizePolicy10);
        btnGoJoin->setMinimumSize(QSize(0, 82));
        btnGoJoin->setFont(font16);

        gridLayout->addWidget(btnGoJoin, 4, 1, 1, 2);

        stackedWidget->addWidget(pageLobby);
        label->raise();
        label_4->raise();
        txtName->raise();
        btnGoCreate->raise();
        btnGoJoin->raise();
        label_5->raise();
        label_6->raise();
        connection->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 899, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        lblRoomInfo->setBuddy(lblRoomInfo);
        lblRoomInfo_2->setBuddy(lblRoomInfo);
#endif // QT_CONFIG(shortcut)

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        CreateRoomBox->setTitle(QCoreApplication::translate("MainWindow", "CREATE ROOM", nullptr));
        balanceEdit->setText(QCoreApplication::translate("MainWindow", "Starting Balance", nullptr));
        editBalance->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Number of Players", nullptr));
        btnCreateRoom->setText(QCoreApplication::translate("MainWindow", "CREATE", nullptr));
        btnBackFromCreate->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        groupBox->setTitle(QString());
        lblRoomInfo->setText(QCoreApplication::translate("MainWindow", "ROOM ID :       ", nullptr));
        lblStatus->setText(QCoreApplication::translate("MainWindow", "STATUS : WAITING", nullptr));
        groupBox_player1->setTitle(QString());
        YOU->setText(QCoreApplication::translate("MainWindow", "YOU", nullptr));
        lblPlayerTotal->setText(QCoreApplication::translate("MainWindow", "TOTAL :  ", nullptr));
        lblWinner->setText(QString());
        groupBox_player2->setTitle(QString());
        lblOppName->setText(QCoreApplication::translate("MainWindow", "lblOppName", nullptr));
        lblOppTotal->setText(QCoreApplication::translate("MainWindow", "TOTAL:   ", nullptr));
        lblPlayerCard1->setText(QString());
        lblPlayerCard2->setText(QString());
        lblPlayerCard3->setText(QString());
        groupBox_2->setTitle(QString());
        YOU_2->setText(QCoreApplication::translate("MainWindow", "DEALER", nullptr));
        lblDealerCard1->setText(QString());
        lblDealerCard2->setText(QString());
        lblDealerCard3->setText(QString());
        lblDealerCard4->setText(QString());
        lblDealerTotal->setText(QCoreApplication::translate("MainWindow", "DEALER TOTAL :      ", nullptr));
        lblOppCard1->setText(QString());
        lblOppCard2->setText(QString());
        lblOppCard3->setText(QString());
        lblPlayerCard4->setText(QString());
        lblPlayerCard5->setText(QString());
        lblPlayerCard6->setText(QString());
        lblOppCard4->setText(QString());
        lblOppCard5->setText(QString());
        lblOppCard6->setText(QString());
        btnSwitchToTable->setText(QCoreApplication::translate("MainWindow", "Tableview", nullptr));
        btnHit->setText(QCoreApplication::translate("MainWindow", "HIT", nullptr));
        btnStand->setText(QCoreApplication::translate("MainWindow", "STAND", nullptr));
        btnLeaveGame1->setText(QCoreApplication::translate("MainWindow", "LEAVE/BACK", nullptr));
        lblRoomInfo_2->setText(QCoreApplication::translate("MainWindow", "ROOM ID :       ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "TOTAL", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "CARDS", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "STOOD", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "DEALER", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "PLAYER1", nullptr));
        btnStand2->setText(QCoreApplication::translate("MainWindow", "STAND", nullptr));
        btnHit2->setText(QCoreApplication::translate("MainWindow", "HIT", nullptr));
        btnSwitchToSimple->setText(QCoreApplication::translate("MainWindow", "SIMPLE VIEW", nullptr));
        btnLeaveGame2->setText(QCoreApplication::translate("MainWindow", "LEAVE/BACK", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "JOIN ROOM", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblRooms->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "ROOM ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblRooms->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "HOST NAME", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblRooms->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "STATUS", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblRooms->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "PLAYER (1/2)", nullptr));
        join_room->setText(QCoreApplication::translate("MainWindow", "JOIN ROOM", nullptr));
        btnBackFromJoin->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        Refresh->setText(QCoreApplication::translate("MainWindow", "REFRESH", nullptr));
        connection->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "BLACK JACK      ", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "NAME : ", nullptr));
        txtName->setText(QString());
        btnGoCreate->setText(QCoreApplication::translate("MainWindow", "CREATE GAME", nullptr));
        btnGoJoin->setText(QCoreApplication::translate("MainWindow", "JOIN GAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
