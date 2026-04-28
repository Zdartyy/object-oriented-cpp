#include <iostream>
using std::cin;
using std::cout;

#include "kolor.h"
#include "fab_kol.h"

struct NiebieskaPolityka
{
    Kolor nieznanyKolor(std::string nazwa)
    {
        return Kolor(0, 0, 255);
    }
};

FabrykaKolorow<NiebieskaPolityka> fabryka;

int main()
{
    try {
        cout << fabryka.zwrocKolor("zielony") << '\n';
        cout << fabryka.zwrocKolor("green") << '\n';
    } catch(...) {
        cout << "Zlapano wyjatek.\n";
    }

    return 0;
}