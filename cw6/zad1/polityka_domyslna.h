#pragma once
#include "kolor.h"
#include <string>

struct NiebieskaPolityka {
    Kolor nieznanyKolor(std::string nazwa) {
        return Kolor(0, 0, 255);
    }
};