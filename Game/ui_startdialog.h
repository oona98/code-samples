/********************************************************************************
** Form generated from reading UI file 'startdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTDIALOG_H
#define UI_STARTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_StartDialog
{
public:
    QPushButton *startButton;
    QLabel *label;
    QRadioButton *quickGameRadioButton;
    QRadioButton *normalGameRadioButton;
    QPushButton *quitButton;
    QLabel *messageLabel;

    void setupUi(QDialog *StartDialog)
    {
        if (StartDialog->objectName().isEmpty())
            StartDialog->setObjectName(QStringLiteral("StartDialog"));
        StartDialog->resize(305, 195);
        QFont font;
        font.setItalic(false);
        StartDialog->setFont(font);
        StartDialog->setStyleSheet(QStringLiteral("QDialog#StartDialog { background-color: rgba(58, 66, 66, 211)}"));
        StartDialog->setModal(false);
        startButton = new QPushButton(StartDialog);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(20, 150, 131, 28));
        label = new QLabel(StartDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 221, 20));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("QLabel#label {color: rgb(255, 255, 255)}"));
        quickGameRadioButton = new QRadioButton(StartDialog);
        quickGameRadioButton->setObjectName(QStringLiteral("quickGameRadioButton"));
        quickGameRadioButton->setGeometry(QRect(30, 80, 111, 26));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        quickGameRadioButton->setFont(font2);
        quickGameRadioButton->setStyleSheet(QLatin1String("QRadioButton#quickGameRadioButton {color: rgb(66, 157, 113)}\n"
"\n"
"\n"
""));
        normalGameRadioButton = new QRadioButton(StartDialog);
        normalGameRadioButton->setObjectName(QStringLiteral("normalGameRadioButton"));
        normalGameRadioButton->setGeometry(QRect(30, 110, 121, 26));
        normalGameRadioButton->setFont(font2);
        normalGameRadioButton->setStyleSheet(QStringLiteral("QRadioButton#normalGameRadioButton {color: rgb(66, 157, 113)}"));
        quitButton = new QPushButton(StartDialog);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(190, 150, 71, 28));
        messageLabel = new QLabel(StartDialog);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        messageLabel->setGeometry(QRect(20, 50, 251, 20));
        QFont font3;
        font3.setPointSize(9);
        messageLabel->setFont(font3);
        messageLabel->setStyleSheet(QStringLiteral("QLabel#messageLabel {color: rgb(255, 255, 255)}"));

        retranslateUi(StartDialog);

        QMetaObject::connectSlotsByName(StartDialog);
    } // setupUi

    void retranslateUi(QDialog *StartDialog)
    {
        StartDialog->setWindowTitle(QApplication::translate("StartDialog", "Start menu", Q_NULLPTR));
        startButton->setText(QApplication::translate("StartDialog", "Start new game", Q_NULLPTR));
        label->setText(QApplication::translate("StartDialog", "Pirkanmaan valloitus", Q_NULLPTR));
        quickGameRadioButton->setText(QApplication::translate("StartDialog", "Quick game", Q_NULLPTR));
        normalGameRadioButton->setText(QApplication::translate("StartDialog", "Normal game", Q_NULLPTR));
        quitButton->setText(QApplication::translate("StartDialog", "Quit", Q_NULLPTR));
        messageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartDialog: public Ui_StartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTDIALOG_H
