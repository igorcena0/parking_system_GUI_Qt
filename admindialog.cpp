#include "admindialog.h"
#include "ui_admindialog.h"
#include "AdministratorParkingu.h"
#include <QInputDialog>
#include <QString>

extern SystemParkingowy* globalnyParking;
extern AdministratorParkingu admin;

AdminDialog::AdminDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminDialog) {
    ui->setupUi(this);
    admin.logger = [this](const std::string& tekst)
    {
        ui->textEditWynik->append(QString::fromStdString(tekst));
    };

}

AdminDialog::~AdminDialog() {
    delete ui;
}

void AdminDialog::on_btnZmienStawke_clicked() {
    bool ok;
    double nowaStawka = QInputDialog::getDouble(this, "Zmiana stawki",
                                                "Nowa stawka za godzinę:", 5.0,
                                                0.0, 999.0, 2, &ok);
    if (!ok) return;

    admin.zmienStawke(nowaStawka);
}

void AdminDialog::on_btnDodajAbonenta_clicked() {
    bool ok;
    QString nr = QInputDialog::getText(this, "Dodaj abonenta",
                                       "Numer rejestracyjny:", QLineEdit::Normal,
                                       "", &ok);
    if (!ok || nr.trimmed().isEmpty()) return;

    admin.dodajAbonenta(nr.trimmed().toStdString());
}

void AdminDialog::on_btnUsunAbonenta_clicked() {
    bool ok;
    QString nr = QInputDialog::getText(this, "Usuń abonenta",
                                       "Numer rejestracyjny:", QLineEdit::Normal,
                                       "", &ok);
    if (!ok || nr.trimmed().isEmpty()) return;

    admin.usunAbonenta(nr.trimmed().toStdString());
}


void AdminDialog::on_btnPokazZajete_clicked() {
    QString wynik;
    for (const auto& m : globalnyParking->miejsca)
        if (m.zajete) wynik += "Zajęte: miejsce " + QString::number(m.id) + "\n";
    ui->textEditWynik->setText(wynik.isEmpty() ? "Brak zajętych miejsc." : wynik);
}

void AdminDialog::on_btnPokazWolne_clicked() {
    QString wynik;
    for (const auto& m : globalnyParking->miejsca)
        if (!m.zajete) wynik += "Wolne: miejsce " + QString::number(m.id) + "\n";
    ui->textEditWynik->setText(wynik.isEmpty() ? "Brak wolnych miejsc." : wynik);
}

void AdminDialog::on_btnPokazHistorie_clicked() {
    QString wynik;
    for (const auto& b : globalnyParking->bilety) {
        wynik += "Bilet ID: " + QString::number(b.id) +
                 ", nr: " + QString::fromStdString(b.nrRej) +
                 ", miejsce: " + QString::number(b.miejsceId) +
                 ", oplacony: " + (b.oplacony ? "tak" : "nie") +
                 ", wyjechal: " + (b.wyjechal ? "tak" : "nie") + "\n";
    }
    ui->textEditWynik->setText(wynik.isEmpty() ? "Brak historii." : wynik);
}
