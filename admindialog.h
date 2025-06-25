#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#pragma once

#include <QDialog>
#include "SystemParkingowy.h"

namespace Ui {
class AdminDialog;
}

class AdminDialog : public QDialog {
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = nullptr);
    ~AdminDialog();

private slots:
    void on_btnZmienStawke_clicked();
    void on_btnDodajAbonenta_clicked();
    void on_btnUsunAbonenta_clicked();
    void on_btnPokazZajete_clicked();
    void on_btnPokazWolne_clicked();
    void on_btnPokazHistorie_clicked();

private:
    Ui::AdminDialog *ui;
};


#endif // ADMINDIALOG_H
