#include "mainwindow.h"
#include "admindialog.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QCloseEvent>

MainWindow::MainWindow(int iloscMiejsc, double stawka, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , parking(iloscMiejsc, stawka)
{
    ui->setupUi(this);
    globalnyParking = &parking;
    aktualizujWidokMiejsc();
    kierowca.logger = [this](const std::string& tekst)
    {
        ui->textStatusMain->setText(QString::fromStdString(tekst));
    };
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        QTime current = QTime::currentTime();
        ui->labelZegar->setText(current.toString("HH:mm:ss"));
    });
    timer->start(1000);
}


MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnWjazd_clicked() {
    bool ok;
    QString nr = QInputDialog::getText(this, "Wjazd pojazdu",
                                       "Numer rejestracyjny:", QLineEdit::Normal,
                                       "", &ok);
    if (!ok || nr.trimmed().isEmpty()) {
        kierowca.logger("[GUI] Anulowano lub brak numeru.");
        return;
    }

    kierowca.wjazdPojazdu(nr.trimmed().toStdString());
    aktualizujWidokMiejsc();
}



void MainWindow::on_btnPlatnosc_clicked() {
    bool ok;
    int id = QInputDialog::getInt(this, "Płatność",
                                  "ID biletu:", 0, 0, 999999, 1, &ok);
    if (!ok) {
        kierowca.logger("[GUI] Anulowano ID biletu.");
        return;
    }

    QString godzina = QInputDialog::getText(this, "Płatność",
                                            "Podaj godzinę wyjazdu (HH:MM):",
                                            QLineEdit::Normal, "", &ok);
    if (!ok || godzina.trimmed().isEmpty()) {
        kierowca.logger("[GUI] Anulowano godzinę.");
        return;
    }

    kierowca.dokonajPlatnosci(id, godzina.trimmed().toStdString());
    aktualizujWidokMiejsc();
}




void MainWindow::on_btnWyjazd_clicked() {
    bool ok;
    int id = QInputDialog::getInt(this, "Wyjazd pojazdu",
                                  "ID biletu:", 0, 0, 999999, 1, &ok);
    if (!ok) {
        kierowca.logger("[GUI] Anulowano.");
        return;
    }

    kierowca.wyjazdPojazdu(id);
    aktualizujWidokMiejsc();
}



void MainWindow::on_btnAdmin_clicked() {
    bool ok;
    QString haslo = QInputDialog::getText(this, "Logowanie administratora",
                                          "Podaj hasło:", QLineEdit::Password,
                                          "", &ok);
    if (!ok || haslo != "admin") {
        QMessageBox::warning(this, "Błąd logowania", "Niepoprawne hasło.");
        return;
    }

    AdminDialog dlg(this);
    dlg.exec();
}


void MainWindow::aktualizujWidokMiejsc() {
    ui->tableMiejsca->setRowCount(parking.miejsca.size());
    ui->tableMiejsca->setColumnCount(2);
    QStringList headers;
    headers << "ID Miejsca" << "Status";
    ui->tableMiejsca->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < parking.miejsca.size(); ++i) {
        const auto& miejsce = parking.miejsca[i];

        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(miejsce.id));
        QTableWidgetItem* statusItem = new QTableWidgetItem(miejsce.zajete ? "Zajęte" : "Wolne");

        QColor kolor = miejsce.zajete ? QColor(255, 100, 100) : QColor(150, 255, 150);
        statusItem->setBackground(QBrush(kolor));

        ui->tableMiejsca->setItem(i, 0, idItem);
        ui->tableMiejsca->setItem(i, 1, statusItem);
    }
    ui->tableMiejsca->resizeColumnsToContents();
    ui->tableMiejsca->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (globalnyParking)
        globalnyParking->zapiszHistorieBiletowDoCSV("historia_biletow.csv");

    event->accept(); // kontynuuj zamykanie
}
