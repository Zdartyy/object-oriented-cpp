#pragma once
#include "kolor.h"
#include <string>

template <int red, int green, int blue>
struct PolitykaDefaultowegoKoloru {
    Kolor nieznanyKolor(std::string nazwa) {
        return Kolor(red, green, blue);
    }
};

typedef PolitykaDefaultowegoKoloru<128, 128, 128> SzaraPolityka;
typedef PolitykaDefaultowegoKoloru<255, 0, 0 > CzerwonaPolityka;
typedef PolitykaDefaultowegoKoloru<0, 0, 255> DomyslnaNiebieskaPolityka;