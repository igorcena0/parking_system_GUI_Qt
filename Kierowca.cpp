#include "Kierowca.h"
#include "SystemParkingowy.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QString>
#include <QTime>
#include <iomanip>
#include <sstream>
#include <QPushButton>

extern SystemParkingowy* globalnyParking;

int Kierowca::wjazdPojazdu(const std::string& nrRej) {
    if (!globalnyParking->walidujNrRej(nrRej)) {
        if (logger) logger("[Kierowca] Niepoprawny numer rejestracyjny (tylko duze litery i cyfry, max 10 znakow).");
        return -1;
    }

    int miejsce = globalnyParking->znajdzWolneMiejsce();
    if (miejsce == -1) {
        if (logger) logger("[Kierowca] Brak wolnych miejsc!");
        return -1;
    }

    if (globalnyParking->znajdzBiletPoNumerze(nrRej) != nullptr) {
        if (logger) logger("[Kierowca] Pojazd z takim numerem juz jest na parkingu.");
        return -1;
    }

    globalnyParking->oznaczMiejsce(miejsce, true);

    Bilet b(globalnyParking->licznikBiletow++, nrRej, miejsce, globalnyParking->stawkaZaGodzine);

    if (globalnyParking->abonenci.find(nrRej) != globalnyParking->abonenci.end()) {
        b.abonament = true;
        b.oplacony = true;
        b.moznaWyjechac = true;
    }

    globalnyParking->dodajBilet(b);
    if (logger) logger("[Kierowca] Wjazd zatwierdzony. Bilet ID: " + std::to_string(b.id) + ", miejsce: " + std::to_string(miejsce));
    return b.id;
}

void Kierowca::wyjazdPojazdu(int idBiletu) {
    Bilet* b = globalnyParking->znajdzBilet(idBiletu);
    if (!b) {
        if (logger) logger("[Kierowca] Bilet nie znaleziony.");
        return;
    }
    if (b->wyjechal) {
        if (logger) logger("[Kierowca] Ten pojazd juz wyjechal z parkingu.");
        return;
    }
    if (!b->oplacony && !b->abonament) {
        if (logger) logger("[Kierowca] Prosze oplacic bilet przed wyjazdem!");
        return;
    }
    if (!b->moznaWyjechac && !b->abonament) {
        if (logger) logger("[Kierowca] Minelo wiecej niz 10 minut od platnosci. Wyjazd niedozwolony.");
        return;
    }

    globalnyParking->oznaczMiejsce(b->miejsceId, false);
    b->wyjechal = true;
    if (logger) logger("[Kierowca] Wyjazd zatwierdzony. Dziekujemy!");
}

void Kierowca::dokonajPlatnosci(int idBiletu, const std::string& godzinaWyjazduStr)
{
    Bilet* b = globalnyParking->znajdzBilet(idBiletu);
    if (!b) {
        if (logger) logger("[Kierowca] Bilet nie znaleziony.");
        return;
    }

    if (b->oplacony) {
        if (logger) logger("[Kierowca] Bilet juz oplacony.");
        return;
    }

    if (b->abonament) {
        b->oplacony = true;
        b->moznaWyjechac = true;
        if (logger) logger("[Kierowca] Abonament - brak oplat.");
        return;
    }

    int h = 0, m = 0;
    size_t pos = godzinaWyjazduStr.find(':');
    if (pos == std::string::npos) {
        if (logger) logger("[Kierowca] Niepoprawny format czasu (oczekiwany HH:MM).");
        return;
    }
    try {
        h = std::stoi(godzinaWyjazduStr.substr(0, pos));
        m = std::stoi(godzinaWyjazduStr.substr(pos + 1));
    }
    catch (...) {
        if (logger) logger("[Kierowca] Niepoprawny format godziny.");
        return;
    }

    if (h < 0 || h > 23 || m < 0 || m > 59) {
        if (logger) logger("[Kierowca] Godzina poza zakresem (0-23:59).");
        return;
    }

    b->symulowanaGodzinaWyjazdu = godzinaWyjazduStr;

    std::time_t czasWjazduT = std::chrono::system_clock::to_time_t(b->czasWjazdu);
    tm localWjazd{};
    localtime_s(&localWjazd, &czasWjazduT);
    localWjazd.tm_hour = h;
    localWjazd.tm_min = m;
    localWjazd.tm_sec = 0;

    std::chrono::system_clock::time_point czasWyjazduSymulowany =
        std::chrono::system_clock::from_time_t(mktime(&localWjazd));

    if (czasWyjazduSymulowany < b->czasWjazdu) {
        localWjazd.tm_mday += 1;
        czasWyjazduSymulowany = std::chrono::system_clock::from_time_t(mktime(&localWjazd));
    }

    b->czasWyjazduSymulowany = czasWyjazduSymulowany;

    std::chrono::duration<double> roznica = czasWyjazduSymulowany - b->czasWjazdu;
    double godziny = std::ceil(roznica.count() / 3600.0);
    if (godziny <= 0) godziny = 1;

    double kwota = godziny * b->stawkaZaGodzine;

    QMessageBox msgBox;
    msgBox.setWindowTitle("Metoda płatności");
    msgBox.setText("Wybierz metodę płatności:");

    auto* gotowkaBtn = msgBox.addButton("Gotówka", QMessageBox::AcceptRole);
    auto* kartaBtn = msgBox.addButton("Karta", QMessageBox::AcceptRole);

    msgBox.addButton(QMessageBox::Cancel);

    msgBox.exec();

    if (msgBox.clickedButton() == gotowkaBtn) {
        if (logger) logger("[Kierowca] Płatność gotówką przyjęta.");
    } else if (msgBox.clickedButton() == kartaBtn) {
        if (logger) logger("[Kierowca] Płatność kartą przyjęta.");
    } else {
        if (logger) logger("[Kierowca] Anulowano płatność.");
        return;
    }

    b->oplacony = true;
    b->moznaWyjechac = true;

    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << kwota;
    if (logger) logger("[Kierowca] Bilet ID " + std::to_string(idBiletu) +
               " zostal oplacony. Czas postoju: " + std::to_string((int)godziny) +
               " godz., kwota: " + ss.str() + " zl.");

}
