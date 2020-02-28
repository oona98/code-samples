#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include <QDialog>
#include <string>

#include "mainwindow.hh"

namespace Ui {
class StartDialog;
}

/**
 * @brief The StartDialog class represents a start menu for the game
 */
class StartDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief StartDialog constructor
     * @param parent is the parent of the StartDialog
     */
    explicit StartDialog(QWidget *parent = 0);

    /**
     * @brief StartDialog destructor
     */
    ~StartDialog();

    /**
     * @brief setMessage sets message to UI
     * @param message is a string that is defined in MainWindow
     */
    void setMessage(std::string message);

private slots:
    /**
     * @brief startGame creates a MainWindow and opens it and closes StartDialog
     */
    void startGame();

    /**
     * @brief on_quickGameRadioButton_clicked is called when user clicks
     * quickGameRadioButton.
     * This slot sets that quick game will be played
     */
    void on_quickGameRadioButton_clicked();

    /**
     * @brief on_normalGameRadioButton_clicked is called when user clicks
     * normalGameRadioButton.
     * This slot sets that normal game will be played
     */
    void on_normalGameRadioButton_clicked();

    /**
     * @brief on_quitButton_clicked is called when user clicks quitButton.
     * This slot closes StartDialog.
     */
    void on_quitButton_clicked();

private:
    Ui::StartDialog* ui_; // a pointer to user interface
};

#endif // STARTDIALOG_HH
