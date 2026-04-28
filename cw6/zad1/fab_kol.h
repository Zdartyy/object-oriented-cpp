#pragma once
#include <string>
#include <stdexcept>
#include "kolor.h"

struct PolitykaDomyslna {
    Kolor nieznanyKolor(std::string nazwa) {
        throw std::runtime_error("Nieznany kolor: " + nazwa);
    }
};

template <typename Polityka = PolitykaDomyslna>
class FabrykaKolorow : private Polityka {
public:
    Kolor zwrocKolor(const std::string& nazwa) {   
        if (nazwa == "czarny") return Kolor(0, 0, 0);
        if (nazwa == "bialy") return Kolor(255, 255, 255);
        if (nazwa == "czerwony") return Kolor(255, 0, 0);
        if (nazwa == "zielony") return Kolor(0, 255, 0);
        if (nazwa == "niebieski") return Kolor(0, 0, 255);

        return Polityka::nieznanyKolor(nazwa);
    }
};