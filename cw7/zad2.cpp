#include <iostream>

template<int N, int M>
struct Pow {
    enum { value = N * Pow<N, M-1>::value };
};

template<int N>
struct Pow<N, 0> {
    enum { value = 1 };
};

int main() {
    std::cout << "2^10 = " << Pow<2, 10>::value << "\n";
    std::cout << "3^4 = " << Pow<3, 4>::value << "\n";
    std::cout << "5^3 = " << Pow<5, 3>::value << "\n";
    return 0;
}