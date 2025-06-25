#include "startdialog.h"
#include "ui_startdialog.h"
#include <QIntValidator>
#include <QDoubleValidator>
#include <QMessageBox>

StartDialog::StartDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartDialog) {
    ui->setupUi(this);

    // Ustawiamy walidatory
    ui->lineEditLiczbaMiejsc->setValidator(new QIntValidator(1, 1000, this));
    ui->lineEditStawka->setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));

    // Zamiast bezpośrednio accept, używamy slotu walidującego
    connect(ui->btnStart, &QPushButton::clicked, this, &StartDialog::onStartClicked);
}

StartDialog::~StartDialog() {
    delete ui;
}

void StartDialog::onStartClicked() {
    QString miejscaText = ui->lineEditLiczbaMiejsc->text().trimmed();
    QString stawkaText = ui->lineEditStawka->text().trimmed();

    if (miejscaText.isEmpty() || stawkaText.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wypełnij oba pola przed rozpoczęciem.");
        return;
    }

    bool ok1, ok2;
    int miejsca = miejscaText.toInt(&ok1);
    double stawka = stawkaText.toDouble(&ok2);

    if (!ok1 || miejsca <= 0 || !ok2 || stawka <= 0.0) {
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawne dane liczbowe.");
        return;
    }

    accept();  // zamknięcie dialogu jeśli wszystko OK
}

int StartDialog::getLiczbaMiejsc() const {
    return ui->lineEditLiczbaMiejsc->text().toInt();
}

double StartDialog::getStawka() const {
    return ui->lineEditStawka->text().toDouble();
}
