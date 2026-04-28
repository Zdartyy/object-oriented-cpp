#include <iostream>
using std::cin;
using std::cout;

#include "kolor.h"
#include "fab_kol.h"

class MojaPolityka
{
public:
    Kolor nieznanyKolor(std::string nazwa)
    { return Kolor(); }
};

FabrykaKolorow<> fabryka;
FabrykaKolorow<MojaPolityka> moja_fabryka;

int main()
{
    try {
        cout << fabryka.zwrocKolor("zielony") << '\n';
        cout << fabryka.zwrocKolor("green") << '\n';
    } catch(...) {
        cout << "Zlapano wyjatek.\n";
    }

    cout << moja_fabryka.zwrocKolor("zielony") << '\n';
    cout << moja_fabryka.zwrocKolor("green") << '\n';

    return 0;
}