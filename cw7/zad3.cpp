#include <iostream>

// O(log N) mnożeń zamiast O(N)
template<unsigned N>
double int_pow(double x) {
    double half = int_pow<N/2>(x);
    return half * half * int_pow<N % 2>(x);
}

template<> double int_pow<1>(double x) { return x; }
template<> double int_pow<0>(double x) { return 1.0; }


int main() {
    std::cout << "2^10 = " << int_pow<10>(2.0) << "\n";
    std::cout << "3^8 = " << int_pow<8>(3.0) << "\n";
    std::cout << "2^16 = " << int_pow<16>(2.0) << "\n";
    return 0;
}