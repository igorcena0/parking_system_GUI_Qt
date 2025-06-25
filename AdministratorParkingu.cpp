#include "AdministratorParkingu.h"
#include "SystemParkingowy.h"
#include <iomanip>
#include <sstream>
#include <ctime>

extern SystemParkingowy* globalnyParking;
AdministratorParkingu admin;

// Funkcja pomocnicza do formatowania czasu jako string
std::string formatTime(const std::chrono::system_clock::time_point& tp) {
    std::time_t czas = std::chrono::system_clock::to_time_t(tp);
    std::tm tm = *std::localtime(&czas);
    std::ostringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M");
    return ss.str();
}

void AdministratorParkingu::dodajAbonenta(const std::string& nrRej) {
    if (globalnyParking->abonenci.count(nrRej)) {
        if (logger) logger("[Admin] Ten numer już jest abonentem: " + nrRej);
        return;
    }

    globalnyParking->abonenci.insert(nrRej);
    if (logger) logger("[Admin] Dodano abonenta: " + nrRej);

    for (auto& b : globalnyParking->bilety) {
        if (b.nrRej == nrRej && !b.wyjechal) {
            b.abonament = true;
            b.oplacony = true;
            b.moznaWyjechac = true;

            if (logger) logger("[Admin] Zaktualizowano bilet ID " + std::to_string(b.id) + " jako abonamentowy (oplacony).");
        }
    }
}


void AdministratorParkingu::usunAbonenta(const std::string& nrRej) {
    if (globalnyParking->abonenci.erase(nrRej)) {
        if (logger) logger("[Admin] Usunięto abonenta: " + nrRej);

        for (auto& b : globalnyParking->bilety) {
            if (b.nrRej == nrRej && !b.wyjechal) {
                b.abonament = false;
                b.oplacony = false;
                b.moznaWyjechac = false;

                if (logger) logger("[Admin] Bilet ID " + std::to_string(b.id) + " wymaga teraz opłaty.");
            }
        }
    } else {
        if (logger) logger("[Admin] Nie znaleziono abonenta: " + nrRej);
    }
}


void AdministratorParkingu::zmienStawke(double nowaStawka) {
    globalnyParking->stawkaZaGodzine = nowaStawka;
    if (logger) logger("[Admin] Ustawiono nową stawkę: " + std::to_string(nowaStawka) + " zł/h");
}

void AdministratorParkingu::pokazHistorieBiletow() {
    if (logger) logger("[Admin] Historia biletów:");

    for (const Bilet& b : globalnyParking->bilety) {
        std::ostringstream ss;
        ss << "ID: " << b.id
           << ", Nr rej: " << b.nrRej
           << ", Miejsce: " << b.miejsceId
           << ", Stawka: " << b.stawkaZaGodzine << " zl";

        if (b.abonament)
            ss << ", [Abonament]";
        else if (b.oplacony)
            ss << ", [Oplacony]";
        else
            ss << ", [Nieoplacony]";

        if (b.wyjechal)
            ss << ", [Wyjechal]";
        else
            ss << ", [Na parkingu]";

        if (b.czasWjazdu.time_since_epoch().count() > 0)
            ss << ", Wjazd: " << formatTime(b.czasWjazdu);

        if (b.czasWyjazduSymulowany.time_since_epoch().count() > 0)
            ss << ", Symulowany wyjazd: " << formatTime(b.czasWyjazduSymulowany);

        if (!b.symulowanaGodzinaWyjazdu.empty())
            ss << ", Godzina (tekst): " << b.symulowanaGodzinaWyjazdu;

        if (logger) logger(ss.str());
    }
}
