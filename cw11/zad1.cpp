#include <concepts>
#include <iostream>

// Sposob 1
template<typename T>
requires std::integral<T>
auto gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Sposob 2
template<typename T>
auto gcd1(T a, T b) requires std::integral<T> {
    if (b == 0) return a;
    return gcd1(b, a % b);
}

// Sposob 3
template<std::integral T>
auto gcd2(T a, T b) {
    if (b == 0) return a;
    return gcd2(b, a % b);
}

// Sposob 4
// a i b moga miec rozne typy, oba musza spelniac std::integral
auto gcd3(std::integral auto a, std::integral auto b) {
    if (b == 0) return a;
    return gcd3(b, a % b);
}

int main() {
    std::cout << "gcd (requires clause): gcd(100, 10) = " << gcd(100, 10)  << "\n";
    std::cout << "gcd1 (trailing requires): gcd1(81, 27) = " << gcd1(81, 27)  << "\n";
    std::cout << "gcd2 (constrained param): gcd2(48, 18) = " << gcd2(48, 18)  << "\n";
    std::cout << "gcd3 (abbreviated template): gcd3(100, 10) = " << gcd3(100, 10) << "\n";

    // Blad kompilacji:

    // gcd(3.14, 1.0);
    // gcd("abc", "x");

    return 0;
}

// Kompilacja: g++ -std=c++20 zad1.cpp -o zad1 && ./zad1