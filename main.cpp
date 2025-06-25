#include <QApplication>
#include "mainwindow.h"
#include "startdialog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    StartDialog start;
    if (start.exec() != QDialog::Accepted)
        return 0;

    int miejsca = start.getLiczbaMiejsc();
    double stawka = start.getStawka();

    MainWindow w(miejsca, stawka);
    w.show();

    return a.exec();
}
