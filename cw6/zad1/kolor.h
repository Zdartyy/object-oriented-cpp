#pragma once
#include <iostream>
#include <string>

struct Kolor {
    int r, g, b;
    Kolor(int r = 0, int g = 0, int b = 0) : r(r), g(g), b(b) {}
};

inline std::ostream& operator<<(std::ostream& os, const Kolor& k) {
    return os << "RGB(" << k.r << ", " << k.g << ", " << k.b << ")";
}