#include <QApplication>

#include "startdialog.hh"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    StartDialog startDialog;
    startDialog.show();
    return app.exec();
}
