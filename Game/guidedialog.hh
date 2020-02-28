#ifndef GUIDEDIALOG_HH
#define GUIDEDIALOG_HH

#include <QDialog>

namespace Ui {
class GuideDialog;
}

/**
 * @brief The GuideDialog class represents a quide window for the game
 */
class GuideDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief GuideDialog constructor
     * @param parent is the parent of the GuideDialog
     */
    explicit GuideDialog(QWidget *parent = 0);

    /**
     * @brief GuideDialog destructor
     */
    ~GuideDialog();

private slots:
    /**
     * @brief on_closeButton_clicked is called when user clicks closeButton.
     * This function closes the GuideDialog.
     */
    void on_closeButton_clicked();

private:
    Ui::GuideDialog* ui_; // a pointer to user interface
};

#endif // GUIDEDIALOG_HH
