#include <iostream>
#include <cmath>

template<int N>
struct Silnia {
    static constexpr long long value = N * Silnia<N-1>::value;
};
template<>
struct Silnia<0> {
    static constexpr long long value = 1;
};

template<unsigned N>
double int_pow(double x) {
    double half = int_pow<N/2>(x);
    return half * half * int_pow<N % 2>(x);
}
template<> double int_pow<1>(double x) { return x; }
template<> double int_pow<0>(double x) { return 1.0; }

template<int K>
double sin_term(double x) {
    constexpr double sign = (K % 2 == 0) ? 1.0 : -1.0;
    constexpr double factorial = static_cast<double>(Silnia<2*K+1>::value);
    return sign * int_pow<2*K+1>(x) / factorial;
}

template<int N>
struct Sin {
    static double compute(double x) {
        return Sin<N-1>::compute(x) + sin_term<N-1>(x);
    }
};
template<>
struct Sin<0> {
    static double compute(double) { return 0.0; }
};

int main() {
    double x = 1.0;
    std::cout << "sin(1) z 1 wyrazem: " << Sin<1>::compute(x) << "\n";
    std::cout << "sin(1) z 2 wyrazami: " << Sin<2>::compute(x) << "\n";
    std::cout << "sin(1) z 3 wyrazami: " << Sin<3>::compute(x) << "\n";
    std::cout << "sin(1) z 5 wyrazami: " << Sin<5>::compute(x) << "\n";
    std::cout << "sin(1) z 7 wyrazami: " << Sin<7>::compute(x) << "\n";
    std::cout << "sin(1) std::sin: " << std::sin(x) << "\n";
    return 0;
}