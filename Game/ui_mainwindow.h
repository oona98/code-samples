/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *turnTextLabel;
    QFrame *line;
    QLabel *moneyTextLabel;
    QLabel *foodTextLabel;
    QLabel *woodTextLabel;
    QLabel *stoneTextLabel;
    QLabel *oreTextLabel;
    QFrame *line2;
    QLabel *moneyDisplayLabel;
    QLabel *foodDisplayLabel;
    QLabel *woodDisplayLabel;
    QLabel *stoneDisplayLabel;
    QLabel *oreDisplayLabel;
    QFrame *line_3;
    QPushButton *HQButton;
    QPushButton *outpostButton;
    QPushButton *boatButton;
    QPushButton *mineButton;
    QPushButton *farmButton;
    QLabel *turnDisplayLabel;
    QPushButton *endTurnButton;
    QPushButton *assignBWButton;
    QPushButton *assignMinerButton;
    QPushButton *assignSaboteurButton;
    QPushButton *endGameButton;
    QLabel *infoLabel;
    QLabel *infoDisplayLabel;
    QPushButton *guideButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 675);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(10, 10, 511, 531));
        turnTextLabel = new QLabel(centralwidget);
        turnTextLabel->setObjectName(QStringLiteral("turnTextLabel"));
        turnTextLabel->setGeometry(QRect(560, 20, 63, 20));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        turnTextLabel->setFont(font);
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(550, 40, 201, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        moneyTextLabel = new QLabel(centralwidget);
        moneyTextLabel->setObjectName(QStringLiteral("moneyTextLabel"));
        moneyTextLabel->setGeometry(QRect(560, 60, 63, 20));
        foodTextLabel = new QLabel(centralwidget);
        foodTextLabel->setObjectName(QStringLiteral("foodTextLabel"));
        foodTextLabel->setGeometry(QRect(560, 90, 63, 20));
        woodTextLabel = new QLabel(centralwidget);
        woodTextLabel->setObjectName(QStringLiteral("woodTextLabel"));
        woodTextLabel->setGeometry(QRect(560, 120, 63, 20));
        stoneTextLabel = new QLabel(centralwidget);
        stoneTextLabel->setObjectName(QStringLiteral("stoneTextLabel"));
        stoneTextLabel->setGeometry(QRect(560, 150, 63, 20));
        oreTextLabel = new QLabel(centralwidget);
        oreTextLabel->setObjectName(QStringLiteral("oreTextLabel"));
        oreTextLabel->setGeometry(QRect(560, 180, 63, 20));
        line2 = new QFrame(centralwidget);
        line2->setObjectName(QStringLiteral("line2"));
        line2->setGeometry(QRect(550, 200, 201, 16));
        line2->setFrameShape(QFrame::HLine);
        line2->setFrameShadow(QFrame::Sunken);
        moneyDisplayLabel = new QLabel(centralwidget);
        moneyDisplayLabel->setObjectName(QStringLiteral("moneyDisplayLabel"));
        moneyDisplayLabel->setGeometry(QRect(620, 60, 63, 20));
        foodDisplayLabel = new QLabel(centralwidget);
        foodDisplayLabel->setObjectName(QStringLiteral("foodDisplayLabel"));
        foodDisplayLabel->setGeometry(QRect(620, 90, 63, 20));
        woodDisplayLabel = new QLabel(centralwidget);
        woodDisplayLabel->setObjectName(QStringLiteral("woodDisplayLabel"));
        woodDisplayLabel->setGeometry(QRect(620, 120, 63, 20));
        stoneDisplayLabel = new QLabel(centralwidget);
        stoneDisplayLabel->setObjectName(QStringLiteral("stoneDisplayLabel"));
        stoneDisplayLabel->setGeometry(QRect(620, 150, 63, 20));
        oreDisplayLabel = new QLabel(centralwidget);
        oreDisplayLabel->setObjectName(QStringLiteral("oreDisplayLabel"));
        oreDisplayLabel->setGeometry(QRect(620, 180, 63, 20));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(550, 330, 201, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        HQButton = new QPushButton(centralwidget);
        HQButton->setObjectName(QStringLiteral("HQButton"));
        HQButton->setGeometry(QRect(570, 350, 151, 28));
        outpostButton = new QPushButton(centralwidget);
        outpostButton->setObjectName(QStringLiteral("outpostButton"));
        outpostButton->setGeometry(QRect(570, 390, 151, 28));
        boatButton = new QPushButton(centralwidget);
        boatButton->setObjectName(QStringLiteral("boatButton"));
        boatButton->setGeometry(QRect(570, 470, 151, 28));
        mineButton = new QPushButton(centralwidget);
        mineButton->setObjectName(QStringLiteral("mineButton"));
        mineButton->setGeometry(QRect(570, 510, 151, 28));
        farmButton = new QPushButton(centralwidget);
        farmButton->setObjectName(QStringLiteral("farmButton"));
        farmButton->setGeometry(QRect(570, 430, 151, 28));
        turnDisplayLabel = new QLabel(centralwidget);
        turnDisplayLabel->setObjectName(QStringLiteral("turnDisplayLabel"));
        turnDisplayLabel->setGeometry(QRect(620, 20, 121, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("FreeMono"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        turnDisplayLabel->setFont(font1);
        endTurnButton = new QPushButton(centralwidget);
        endTurnButton->setObjectName(QStringLiteral("endTurnButton"));
        endTurnButton->setGeometry(QRect(590, 550, 111, 28));
        assignBWButton = new QPushButton(centralwidget);
        assignBWButton->setObjectName(QStringLiteral("assignBWButton"));
        assignBWButton->setGeometry(QRect(570, 220, 151, 28));
        assignMinerButton = new QPushButton(centralwidget);
        assignMinerButton->setObjectName(QStringLiteral("assignMinerButton"));
        assignMinerButton->setGeometry(QRect(570, 260, 151, 28));
        assignSaboteurButton = new QPushButton(centralwidget);
        assignSaboteurButton->setObjectName(QStringLiteral("assignSaboteurButton"));
        assignSaboteurButton->setGeometry(QRect(573, 300, 151, 28));
        endGameButton = new QPushButton(centralwidget);
        endGameButton->setObjectName(QStringLiteral("endGameButton"));
        endGameButton->setGeometry(QRect(120, 550, 101, 28));
        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        infoLabel->setGeometry(QRect(240, 555, 41, 21));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        infoLabel->setFont(font2);
        infoDisplayLabel = new QLabel(centralwidget);
        infoDisplayLabel->setObjectName(QStringLiteral("infoDisplayLabel"));
        infoDisplayLabel->setGeometry(QRect(280, 555, 261, 21));
        guideButton = new QPushButton(centralwidget);
        guideButton->setObjectName(QStringLiteral("guideButton"));
        guideButton->setGeometry(QRect(20, 550, 84, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pirkanmaan valloitus", Q_NULLPTR));
        turnTextLabel->setText(QApplication::translate("MainWindow", "Turn:", Q_NULLPTR));
        moneyTextLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Money:</span></p></body></html>", Q_NULLPTR));
        foodTextLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Food:</span></p></body></html>", Q_NULLPTR));
        woodTextLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Wood:</span></p></body></html>", Q_NULLPTR));
        stoneTextLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Stone:</span></p></body></html>", Q_NULLPTR));
        oreTextLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Ore:</span></p></body></html>", Q_NULLPTR));
        moneyDisplayLabel->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        foodDisplayLabel->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        woodDisplayLabel->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        stoneDisplayLabel->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        oreDisplayLabel->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        HQButton->setText(QApplication::translate("MainWindow", "Build a head quarter", Q_NULLPTR));
        outpostButton->setText(QApplication::translate("MainWindow", "Build an outpost", Q_NULLPTR));
        boatButton->setText(QApplication::translate("MainWindow", "Build a boat", Q_NULLPTR));
        mineButton->setText(QApplication::translate("MainWindow", "Build a mine", Q_NULLPTR));
        farmButton->setText(QApplication::translate("MainWindow", "Build a farm", Q_NULLPTR));
        turnDisplayLabel->setText(QApplication::translate("MainWindow", "moi", Q_NULLPTR));
        endTurnButton->setText(QApplication::translate("MainWindow", "Switch turn", Q_NULLPTR));
        assignBWButton->setText(QApplication::translate("MainWindow", "Assign a basic worker", Q_NULLPTR));
        assignMinerButton->setText(QApplication::translate("MainWindow", "Assign a miner", Q_NULLPTR));
        assignSaboteurButton->setText(QApplication::translate("MainWindow", "Assign a saboteur", Q_NULLPTR));
        endGameButton->setText(QApplication::translate("MainWindow", "End this game", Q_NULLPTR));
        infoLabel->setText(QApplication::translate("MainWindow", "Info:", Q_NULLPTR));
        infoDisplayLabel->setText(QApplication::translate("MainWindow", "Click the map for adding objects", Q_NULLPTR));
        guideButton->setText(QApplication::translate("MainWindow", "Guide", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
