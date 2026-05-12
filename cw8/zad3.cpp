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

template<typename LHS, typename RHS>
struct AddExpr {
    LHS _l; RHS _r;
    AddExpr(const LHS& l, const RHS& r) : _l(l), _r(r) {}
    double operator()(double x) const { return _l(x) + _r(x); }
};

template<typename LHS, typename RHS>
AddExpr<LHS, RHS> operator+(const LHS& l, const RHS& r) {
    return AddExpr<LHS, RHS>(l, r);
}

template<typename LHS>
AddExpr<LHS, Constant> operator+(const LHS& l, double r) {
    return AddExpr<LHS, Constant>(l, Constant(r));
}

template<typename RHS>
AddExpr<Constant, RHS> operator+(double l, const RHS& r) {
    return AddExpr<Constant, RHS>(Constant(l), r);
}

int main() {
    Variable x;

    std::cout << integrate(x + 1., 0, 1, 0.001) << "\n";
    return 0;
}