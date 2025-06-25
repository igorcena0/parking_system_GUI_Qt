#pragma once
#include <functional>
#include <string>
class AdministratorParkingu {
public:
    void panelAdmina();
    std::function<void(const std::string&)> logger;
    void zmienStawke(double nowaStawka);
    void dodajAbonenta(const std::string& nrRej);
    void usunAbonenta(const std::string& nrRej);
private:
    bool zaloguj();
    void pokazZajeteMiejsca();
    void pokazWolneMiejsca();
    void pokazHistorieBiletow();
};
