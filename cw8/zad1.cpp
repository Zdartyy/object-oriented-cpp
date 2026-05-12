#include <iostream>
#include <cmath>
#include "integrate.h"

struct sina {
    int _n;
    explicit sina(int n) : _n(n) {}
    double operator()(double x) const {
        return std::pow(std::sin(x), _n);
    }
};

int main() {
    std::cout << integrate(sina(0), 0, 3.1415926, 0.01) << "\n";
    std::cout << integrate(sina(1), 0, 3.1415926, 0.01) << "\n";
    std::cout << integrate(sina(2), 0, 3.1415926, 0.01) << "\n";
    return 0;
}