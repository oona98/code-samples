#include <QString>

#include "startdialog.hh"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::StartDialog)
{
    ui_->setupUi(this);

    connect(ui_->startButton, SIGNAL(clicked()), this, SLOT(startGame()));

    ui_->normalGameRadioButton->setChecked(true);
}

StartDialog::~StartDialog() {
    delete ui_;
}

void StartDialog::setMessage(std::string message) {
    ui_->messageLabel->setText(QString::fromStdString(message));
}

void StartDialog::startGame() {
    MainWindow* mainWindow = new MainWindow;

    // Checks whether quick or normal game will be played
    if (ui_->normalGameRadioButton->isChecked()) {
        mainWindow->setScale(60);
        mainWindow->setSize(8, 8);
    } else {
        mainWindow->setScale(100);
        mainWindow->setSize(5, 5);
    }

    mainWindow->show();
    close();
}

void StartDialog::on_quickGameRadioButton_clicked() {
    ui_->normalGameRadioButton->setChecked(false);
}

void StartDialog::on_normalGameRadioButton_clicked() {
    ui_->quickGameRadioButton->setChecked(false);
}

void StartDialog::on_quitButton_clicked() {
    close();
}
