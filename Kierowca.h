#pragma once
#include <string>
#include <functional>

class Kierowca {
public:
    std::function<void(const std::string&)> logger;
    int wjazdPojazdu(const std::string& nrRej);
    void wyjazdPojazdu(int idBiletu);
    void dokonajPlatnosci(int idBiletu, const std::string& godzinaWyjazdu);
};
