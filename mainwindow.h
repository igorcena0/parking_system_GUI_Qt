#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include "SystemParkingowy.h"
#include "Kierowca.h"
#include "AdministratorParkingu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(int iloscMiejsc, double stawka, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnWjazd_clicked();
    void on_btnPlatnosc_clicked();
    void on_btnWyjazd_clicked();
    void on_btnAdmin_clicked();

private:
    Ui::MainWindow *ui;
    SystemParkingowy parking;
    Kierowca kierowca;
    AdministratorParkingu admin;
    void aktualizujWidokMiejsc();

protected:
    void closeEvent(QCloseEvent *event) override;

};

#endif
