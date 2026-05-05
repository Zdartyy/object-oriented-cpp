#include <iostream>

template<size_t N>
struct InnerProduct {
    static double compute(double* x, double* y) {
        return x[N-1] * y[N-1] + InnerProduct<N-1>::compute(x, y);
    }
};
template<>
struct InnerProduct<0> {
    static double compute(double*, double*) { return 0.0; }
};

template<size_t N>
double inner(double* x, double* y) {
    return InnerProduct<N>::compute(x, y);
}

int main() {
    double a[] = {1.0, 2.0, 3.0};
    double b[] = {4.0, 5.0, 6.0};

    std::cout << "inner<3> = " << inner<3>(a, b) << "\n";

    double c[] = {1, 0, 0, 0};
    double d[] = {0, 0, 0, 1};
    std::cout << "inner<4> = " << inner<4>(c, d) << "\n";
    return 0;
}