#include <iostream>
#include "integrate.h"

struct Variable {
    double operator()(double x) const { return x; }
};

struct Constant {
    double _val;
    explicit Constant(double val) : _val(val) {}
    double operator()(double x) const { return _val; }
};

int main() {
    Variable x;

    std::cout << integrate(x, 0, 1, 0.001) << "\n";
    std::cout << integrate(Constant(1.0), 0, 1, 0.001) << "\n";
    return 0;
}