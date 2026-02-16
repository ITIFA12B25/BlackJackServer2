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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
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
    QFormLayout *formLayout;
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
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QPushButton *btnStand;
    QLabel *lblRoomInfo;
    QLabel *lblStatus;
    QLabel *lblPlayerCard3;
    QLabel *lblOppCard2;
    QPushButton *btnSwitchToTable;
    QGroupBox *groupBox_player2;
    QLabel *lblOppTotal;
    QLabel *lblOppName;
    QLabel *lblPlayerCard4;
    QLabel *lblPlayerCard1;
    QLabel *lblOppCard1;
    QGroupBox *groupBox_2;
    QLabel *lblDealerCard1;
    QLabel *lblDealerCard3;
    QLabel *lblDealerCard2;
    QLabel *lblDealerCard4;
    QPushButton *btnNewRound_2;
    QLabel *lblPlayerCard2;
    QGroupBox *groupBox_player1;
    QGridLayout *gridLayout_4;
    QLabel *lblPlayerTotal;
    QPushButton *btnLeaveGame1;
    QPushButton *btnHit;
    QLabel *lblOppCard3;
    QLabel *lblDealerTotal;
    QLabel *lblOppCard4;
    QLabel *lblWinner;
    QWidget *pageGameTable;
    QGridLayout *gridLayout_2;
    QPushButton *btnLeaveGame2;
    QPushButton *btnSwitchToSimple;
    QLabel *lblRoomInfo_2;
    QPushButton *btnHit2;
    QTableWidget *tableWidget;
    QPushButton *btnNewRound;
    QPushButton *btnStand2;
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
    QLineEdit *txtName;
    QPushButton *btnGoCreate;
    QPushButton *btnGoJoin;
    QPushButton *History;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(false);
        MainWindow->resize(792, 594);
        QFont font;
        font.setPointSize(8);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(6, 129, 67);\n"
"\n"
""));
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(false);
        pageCreateRoom = new QWidget();
        pageCreateRoom->setObjectName("pageCreateRoom");
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
        horizontalLayout = new QHBoxLayout(pageGameSimple);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(pageGameSimple);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(741, 200));
        groupBox->setAutoFillBackground(false);
        btnStand = new QPushButton(groupBox);
        btnStand->setObjectName("btnStand");
        btnStand->setGeometry(QRect(380, 460, 140, 45));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnStand->sizePolicy().hasHeightForWidth());
        btnStand->setSizePolicy(sizePolicy2);
        btnStand->setMinimumSize(QSize(0, 45));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font4.setPointSize(18);
        btnStand->setFont(font4);
        btnStand->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lblRoomInfo = new QLabel(groupBox);
        lblRoomInfo->setObjectName("lblRoomInfo");
        lblRoomInfo->setGeometry(QRect(12, 15, 725, 25));
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblRoomInfo->sizePolicy().hasHeightForWidth());
        lblRoomInfo->setSizePolicy(sizePolicy3);
        lblRoomInfo->setMinimumSize(QSize(713, 25));
        lblRoomInfo->setMaximumSize(QSize(16777215, 500));
        lblRoomInfo->setFont(font2);
        lblRoomInfo->setTextFormat(Qt::TextFormat::AutoText);
        lblRoomInfo->setScaledContents(true);
        lblRoomInfo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblStatus = new QLabel(groupBox);
        lblStatus->setObjectName("lblStatus");
        lblStatus->setGeometry(QRect(218, 46, 112, 16));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font5.setPointSize(8);
        lblStatus->setFont(font5);
        lblPlayerCard3 = new QLabel(groupBox);
        lblPlayerCard3->setObjectName("lblPlayerCard3");
        lblPlayerCard3->setGeometry(QRect(12, 256, 72, 108));
        lblPlayerCard3->setMinimumSize(QSize(72, 108));
        lblOppCard2 = new QLabel(groupBox);
        lblOppCard2->setObjectName("lblOppCard2");
        lblOppCard2->setGeometry(QRect(525, 162, 72, 108));
        sizePolicy1.setHeightForWidth(lblOppCard2->sizePolicy().hasHeightForWidth());
        lblOppCard2->setSizePolicy(sizePolicy1);
        lblOppCard2->setMinimumSize(QSize(72, 108));
        btnSwitchToTable = new QPushButton(groupBox);
        btnSwitchToTable->setObjectName("btnSwitchToTable");
        btnSwitchToTable->setGeometry(QRect(10, 460, 140, 45));
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnSwitchToTable->sizePolicy().hasHeightForWidth());
        btnSwitchToTable->setSizePolicy(sizePolicy4);
        btnSwitchToTable->setMinimumSize(QSize(0, 45));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font6.setPointSize(14);
        btnSwitchToTable->setFont(font6);
        groupBox_player2 = new QGroupBox(groupBox);
        groupBox_player2->setObjectName("groupBox_player2");
        groupBox_player2->setGeometry(QRect(525, 68, 212, 100));
        sizePolicy1.setHeightForWidth(groupBox_player2->sizePolicy().hasHeightForWidth());
        groupBox_player2->setSizePolicy(sizePolicy1);
        groupBox_player2->setMinimumSize(QSize(200, 100));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font7.setPointSize(13);
        groupBox_player2->setFont(font7);
        lblOppTotal = new QLabel(groupBox_player2);
        lblOppTotal->setObjectName("lblOppTotal");
        lblOppTotal->setGeometry(QRect(10, 30, 49, 16));
        lblOppTotal->setFont(font5);
        lblOppName = new QLabel(groupBox_player2);
        lblOppName->setObjectName("lblOppName");
        lblOppName->setGeometry(QRect(10, 0, 91, 23));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font8.setPointSize(12);
        lblOppName->setFont(font8);
        lblPlayerCard4 = new QLabel(groupBox);
        lblPlayerCard4->setObjectName("lblPlayerCard4");
        lblPlayerCard4->setGeometry(QRect(102, 256, 72, 108));
        lblPlayerCard4->setMinimumSize(QSize(72, 108));
        lblPlayerCard1 = new QLabel(groupBox);
        lblPlayerCard1->setObjectName("lblPlayerCard1");
        lblPlayerCard1->setGeometry(QRect(12, 162, 72, 108));
        lblPlayerCard1->setMinimumSize(QSize(72, 108));
        lblOppCard1 = new QLabel(groupBox);
        lblOppCard1->setObjectName("lblOppCard1");
        lblOppCard1->setGeometry(QRect(603, 162, 72, 108));
        lblOppCard1->setMinimumSize(QSize(72, 108));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(218, 162, 301, 211));
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(32);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy5);
        groupBox_2->setMinimumSize(QSize(280, 150));
        groupBox_2->setFont(font7);
        lblDealerCard1 = new QLabel(groupBox_2);
        lblDealerCard1->setObjectName("lblDealerCard1");
        lblDealerCard1->setGeometry(QRect(12, 35, 90, 135));
        lblDealerCard1->setMinimumSize(QSize(70, 105));
        lblDealerCard3 = new QLabel(groupBox_2);
        lblDealerCard3->setObjectName("lblDealerCard3");
        lblDealerCard3->setGeometry(QRect(117, 35, 90, 135));
        lblDealerCard3->setMinimumSize(QSize(70, 105));
        lblDealerCard2 = new QLabel(groupBox_2);
        lblDealerCard2->setObjectName("lblDealerCard2");
        lblDealerCard2->setGeometry(QRect(67, 35, 90, 135));
        lblDealerCard2->setMinimumSize(QSize(70, 105));
        lblDealerCard4 = new QLabel(groupBox_2);
        lblDealerCard4->setObjectName("lblDealerCard4");
        lblDealerCard4->setGeometry(QRect(167, 35, 90, 135));
        lblDealerCard4->setMinimumSize(QSize(70, 105));
        lblDealerCard4->raise();
        lblDealerCard3->raise();
        lblDealerCard2->raise();
        lblDealerCard1->raise();
        btnNewRound_2 = new QPushButton(groupBox);
        btnNewRound_2->setObjectName("btnNewRound_2");
        btnNewRound_2->setGeometry(QRect(600, 410, 140, 45));
        sizePolicy4.setHeightForWidth(btnNewRound_2->sizePolicy().hasHeightForWidth());
        btnNewRound_2->setSizePolicy(sizePolicy4);
        btnNewRound_2->setMinimumSize(QSize(0, 45));
        btnNewRound_2->setFont(font6);
        lblPlayerCard2 = new QLabel(groupBox);
        lblPlayerCard2->setObjectName("lblPlayerCard2");
        lblPlayerCard2->setGeometry(QRect(102, 162, 72, 108));
        lblPlayerCard2->setMinimumSize(QSize(72, 108));
        groupBox_player1 = new QGroupBox(groupBox);
        groupBox_player1->setObjectName("groupBox_player1");
        groupBox_player1->setGeometry(QRect(10, 68, 200, 100));
        sizePolicy1.setHeightForWidth(groupBox_player1->sizePolicy().hasHeightForWidth());
        groupBox_player1->setSizePolicy(sizePolicy1);
        groupBox_player1->setMinimumSize(QSize(200, 100));
        groupBox_player1->setFont(font7);
        gridLayout_4 = new QGridLayout(groupBox_player1);
        gridLayout_4->setObjectName("gridLayout_4");
        lblPlayerTotal = new QLabel(groupBox_player1);
        lblPlayerTotal->setObjectName("lblPlayerTotal");
        lblPlayerTotal->setFont(font5);

        gridLayout_4->addWidget(lblPlayerTotal, 0, 0, 1, 1);

        btnLeaveGame1 = new QPushButton(groupBox);
        btnLeaveGame1->setObjectName("btnLeaveGame1");
        btnLeaveGame1->setGeometry(QRect(600, 460, 140, 45));
        sizePolicy4.setHeightForWidth(btnLeaveGame1->sizePolicy().hasHeightForWidth());
        btnLeaveGame1->setSizePolicy(sizePolicy4);
        btnLeaveGame1->setMinimumSize(QSize(0, 45));
        btnLeaveGame1->setFont(font6);
        btnHit = new QPushButton(groupBox);
        btnHit->setObjectName("btnHit");
        btnHit->setGeometry(QRect(230, 460, 140, 45));
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(btnHit->sizePolicy().hasHeightForWidth());
        btnHit->setSizePolicy(sizePolicy6);
        btnHit->setMinimumSize(QSize(0, 45));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font9.setPointSize(17);
        btnHit->setFont(font9);
        lblOppCard3 = new QLabel(groupBox);
        lblOppCard3->setObjectName("lblOppCard3");
        lblOppCard3->setGeometry(QRect(525, 256, 72, 108));
        lblOppCard3->setMinimumSize(QSize(72, 108));
        lblDealerTotal = new QLabel(groupBox);
        lblDealerTotal->setObjectName("lblDealerTotal");
        lblDealerTotal->setGeometry(QRect(220, 350, 110, 16));
        lblDealerTotal->setMinimumSize(QSize(0, 15));
        lblDealerTotal->setFont(font5);
        lblOppCard4 = new QLabel(groupBox);
        lblOppCard4->setObjectName("lblOppCard4");
        lblOppCard4->setGeometry(QRect(603, 256, 72, 108));
        lblOppCard4->setMinimumSize(QSize(72, 108));
        lblWinner = new QLabel(groupBox);
        lblWinner->setObjectName("lblWinner");
        lblWinner->setGeometry(QRect(230, 60, 211, 81));
        lblWinner->setFont(font9);
        lblRoomInfo->raise();
        lblStatus->raise();
        lblPlayerCard1->raise();
        lblPlayerCard2->raise();
        groupBox_2->raise();
        lblOppCard2->raise();
        lblOppCard1->raise();
        btnNewRound_2->raise();
        btnHit->raise();
        lblDealerTotal->raise();
        lblPlayerCard3->raise();
        lblPlayerCard4->raise();
        lblOppCard3->raise();
        lblOppCard4->raise();
        btnStand->raise();
        btnLeaveGame1->raise();
        groupBox_player2->raise();
        btnSwitchToTable->raise();
        groupBox_player1->raise();
        lblWinner->raise();

        horizontalLayout->addWidget(groupBox);

        stackedWidget->addWidget(pageGameSimple);
        pageGameTable = new QWidget();
        pageGameTable->setObjectName("pageGameTable");
        gridLayout_2 = new QGridLayout(pageGameTable);
        gridLayout_2->setObjectName("gridLayout_2");
        btnLeaveGame2 = new QPushButton(pageGameTable);
        btnLeaveGame2->setObjectName("btnLeaveGame2");
        btnLeaveGame2->setMinimumSize(QSize(0, 45));
        btnLeaveGame2->setFont(font9);

        gridLayout_2->addWidget(btnLeaveGame2, 4, 2, 1, 1);

        btnSwitchToSimple = new QPushButton(pageGameTable);
        btnSwitchToSimple->setObjectName("btnSwitchToSimple");
        btnSwitchToSimple->setMinimumSize(QSize(0, 45));
        btnSwitchToSimple->setFont(font9);

        gridLayout_2->addWidget(btnSwitchToSimple, 3, 2, 1, 1);

        lblRoomInfo_2 = new QLabel(pageGameTable);
        lblRoomInfo_2->setObjectName("lblRoomInfo_2");
        sizePolicy3.setHeightForWidth(lblRoomInfo_2->sizePolicy().hasHeightForWidth());
        lblRoomInfo_2->setSizePolicy(sizePolicy3);
        lblRoomInfo_2->setMinimumSize(QSize(713, 50));
        lblRoomInfo_2->setMaximumSize(QSize(16777215, 500));
        lblRoomInfo_2->setFont(font2);
        lblRoomInfo_2->setTextFormat(Qt::TextFormat::AutoText);
        lblRoomInfo_2->setScaledContents(true);
        lblRoomInfo_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblRoomInfo_2, 0, 0, 1, 3);

        btnHit2 = new QPushButton(pageGameTable);
        btnHit2->setObjectName("btnHit2");
        btnHit2->setMaximumSize(QSize(100, 100));
        btnHit2->setFont(font9);

        gridLayout_2->addWidget(btnHit2, 4, 0, 1, 1);

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
        tableWidget->setFont(font8);

        gridLayout_2->addWidget(tableWidget, 1, 0, 1, 3);

        btnNewRound = new QPushButton(pageGameTable);
        btnNewRound->setObjectName("btnNewRound");
        btnNewRound->setFont(font9);

        gridLayout_2->addWidget(btnNewRound, 2, 2, 1, 1);

        btnStand2 = new QPushButton(pageGameTable);
        btnStand2->setObjectName("btnStand2");
        btnStand2->setMinimumSize(QSize(0, 45));
        btnStand2->setMaximumSize(QSize(100, 100));
        btnStand2->setFont(font9);

        gridLayout_2->addWidget(btnStand2, 3, 0, 1, 1);

        stackedWidget->addWidget(pageGameTable);
        pageJoinRoom = new QWidget();
        pageJoinRoom->setObjectName("pageJoinRoom");
        verticalLayout_3 = new QVBoxLayout(pageJoinRoom);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(pageJoinRoom);
        label_3->setObjectName("label_3");
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font10.setPointSize(26);
        font10.setWeight(QFont::ExtraBold);
        label_3->setFont(font10);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        tblRooms = new QTableWidget(pageJoinRoom);
        if (tblRooms->columnCount() < 4)
            tblRooms->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font6);
        tblRooms->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font6);
        tblRooms->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font6);
        tblRooms->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblRooms->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        if (tblRooms->rowCount() < 3)
            tblRooms->setRowCount(3);
        tblRooms->setObjectName("tblRooms");
        tblRooms->setMaximumSize(QSize(16777215, 16777177));
        tblRooms->setFont(font8);
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
        sizePolicy6.setHeightForWidth(join_room->sizePolicy().hasHeightForWidth());
        join_room->setSizePolicy(sizePolicy6);
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
        sizePolicy6.setHeightForWidth(btnBackFromJoin->sizePolicy().hasHeightForWidth());
        btnBackFromJoin->setSizePolicy(sizePolicy6);
        btnBackFromJoin->setMinimumSize(QSize(0, 50));
        btnBackFromJoin->setFont(font4);

        verticalLayout_3->addWidget(btnBackFromJoin);

        Refresh = new QPushButton(pageJoinRoom);
        Refresh->setObjectName("Refresh");
        Refresh->setEnabled(false);
        sizePolicy6.setHeightForWidth(Refresh->sizePolicy().hasHeightForWidth());
        Refresh->setSizePolicy(sizePolicy6);
        Refresh->setMinimumSize(QSize(0, 50));
        Refresh->setFont(font4);

        verticalLayout_3->addWidget(Refresh);

        stackedWidget->addWidget(pageJoinRoom);
        pageLobby = new QWidget();
        pageLobby->setObjectName("pageLobby");
        pageLobby->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(pageLobby);
        gridLayout->setObjectName("gridLayout");
        connection = new QLabel(pageLobby);
        connection->setObjectName("connection");
        connection->setMinimumSize(QSize(15, 15));

        gridLayout->addWidget(connection, 0, 0, 1, 1);

        label = new QLabel(pageLobby);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 250));
        QFont font12;
        font12.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font12.setPointSize(44);
        font12.setWeight(QFont::ExtraBold);
        label->setFont(font12);
        label->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label->setTextFormat(Qt::TextFormat::PlainText);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        txtName = new QLineEdit(pageLobby);
        txtName->setObjectName("txtName");
        txtName->setMinimumSize(QSize(0, 50));
        QFont font13;
        font13.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font13.setPointSize(19);
        txtName->setFont(font13);

        gridLayout->addWidget(txtName, 2, 0, 1, 1);

        btnGoCreate = new QPushButton(pageLobby);
        btnGoCreate->setObjectName("btnGoCreate");
        btnGoCreate->setEnabled(false);
        btnGoCreate->setMinimumSize(QSize(0, 50));
        btnGoCreate->setFont(font13);
        btnGoCreate->setStyleSheet(QString::fromUtf8("outline: rgb(0,0,0);"));

        gridLayout->addWidget(btnGoCreate, 3, 0, 1, 1);

        btnGoJoin = new QPushButton(pageLobby);
        btnGoJoin->setObjectName("btnGoJoin");
        btnGoJoin->setMinimumSize(QSize(0, 50));
        btnGoJoin->setFont(font13);

        gridLayout->addWidget(btnGoJoin, 4, 0, 1, 1);

        History = new QPushButton(pageLobby);
        History->setObjectName("History");
        History->setMinimumSize(QSize(0, 50));
        History->setFont(font13);

        gridLayout->addWidget(History, 5, 0, 1, 1);

        stackedWidget->addWidget(pageLobby);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 792, 25));
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
        btnStand->setText(QCoreApplication::translate("MainWindow", "STAND", nullptr));
        lblRoomInfo->setText(QCoreApplication::translate("MainWindow", "ROOM ID :       ", nullptr));
        lblStatus->setText(QCoreApplication::translate("MainWindow", "STATUS : WAITING", nullptr));
        lblPlayerCard3->setText(QString());
        lblOppCard2->setText(QString());
        btnSwitchToTable->setText(QCoreApplication::translate("MainWindow", "Tableview", nullptr));
        groupBox_player2->setTitle(QCoreApplication::translate("MainWindow", "\343\205\244\343\205\244\343\205\244\343\205\244\343\205\244", nullptr));
        lblOppTotal->setText(QCoreApplication::translate("MainWindow", "TOTAL:   ", nullptr));
        lblOppName->setText(QCoreApplication::translate("MainWindow", "lblOppName", nullptr));
        lblPlayerCard4->setText(QString());
        lblPlayerCard1->setText(QString());
        lblOppCard1->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "DEALER", nullptr));
        lblDealerCard1->setText(QString());
        lblDealerCard3->setText(QString());
        lblDealerCard2->setText(QString());
        lblDealerCard4->setText(QString());
        btnNewRound_2->setText(QCoreApplication::translate("MainWindow", "NEW ROUND", nullptr));
        lblPlayerCard2->setText(QString());
        groupBox_player1->setTitle(QCoreApplication::translate("MainWindow", "YOU ", nullptr));
        lblPlayerTotal->setText(QCoreApplication::translate("MainWindow", "TOTAL :  ", nullptr));
        btnLeaveGame1->setText(QCoreApplication::translate("MainWindow", "LEAVE/BACK", nullptr));
        btnHit->setText(QCoreApplication::translate("MainWindow", "HIT", nullptr));
        lblOppCard3->setText(QString());
        lblDealerTotal->setText(QCoreApplication::translate("MainWindow", "DEALER TOTAL :      ", nullptr));
        lblOppCard4->setText(QString());
        lblWinner->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnLeaveGame2->setText(QCoreApplication::translate("MainWindow", "LEAVE/BACK", nullptr));
        btnSwitchToSimple->setText(QCoreApplication::translate("MainWindow", "SIMPLE VIEW", nullptr));
        lblRoomInfo_2->setText(QCoreApplication::translate("MainWindow", "ROOM ID :       ", nullptr));
        btnHit2->setText(QCoreApplication::translate("MainWindow", "HIT", nullptr));
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
        btnNewRound->setText(QCoreApplication::translate("MainWindow", "NEW ROUND", nullptr));
        btnStand2->setText(QCoreApplication::translate("MainWindow", "STAND", nullptr));
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
        connection->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "BLACK JACK", nullptr));
        txtName->setText(QCoreApplication::translate("MainWindow", "NAME:", nullptr));
        btnGoCreate->setText(QCoreApplication::translate("MainWindow", "CREATE GAME", nullptr));
        btnGoJoin->setText(QCoreApplication::translate("MainWindow", "JOIN GAME", nullptr));
        History->setText(QCoreApplication::translate("MainWindow", "HISTORY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
