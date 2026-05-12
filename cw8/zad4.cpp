#include <iostream>
#include <cmath>
#include "integrate.h"

struct Variable {
    double operator()(double x) const { return x; }
};

struct Constant {
    double _val;
    explicit Constant(double val) : _val(val) {}
    double operator()(double x) const { return _val; }
};

template<typename LHS, typename RHS>
struct AddExpr {
    LHS _l; RHS _r;
    AddExpr(const LHS& l, const RHS& r) : _l(l), _r(r) {}
    double operator()(double x) const { return _l(x) + _r(x); }
};

template<typename LHS, typename RHS>
struct DivExpr {
    LHS _l; RHS _r;
    DivExpr(const LHS& l, const RHS& r) : _l(l), _r(r) {}
    double operator()(double x) const { return _l(x) / _r(x); }
};

template<typename ARG>
struct SinExpr {
    ARG _arg;
    explicit SinExpr(const ARG& arg) : _arg(arg) {}
    double operator()(double x) const { return std::sin(_arg(x)); }
};

template<typename LHS>
AddExpr<LHS, Constant> operator+(const LHS& l, double r) {
    return AddExpr<LHS, Constant>(l, Constant(r));
}

template<typename LHS, typename RHS>
AddExpr<LHS, RHS> operator+(const LHS& l, const RHS& r) {
    return AddExpr<LHS, RHS>(l, r);
}

template<typename RHS>
DivExpr<Constant, RHS> operator/(double l, const RHS& r) {
    return DivExpr<Constant, RHS>(Constant(l), r);
}

template<typename ARG>
SinExpr<ARG> sin(const ARG& arg) {
    return SinExpr<ARG>(arg);
}

int main() {
    Variable x;

    std::cout << integrate(1./sin(x + 1.), 0, 1, 0.001) << "\n";
    return 0;
}