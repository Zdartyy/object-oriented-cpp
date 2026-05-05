#include <iostream>

template<int N>
struct Silnia {
    enum { value = N * Silnia<N-1>::value };
};

template<>
struct Silnia<0> {
    enum { value = 1 };
};

int main() {
    std::cout << "0! = " << Silnia<0>::value << "\n";
    std::cout << "5! = " << Silnia<5>::value << "\n";
    std::cout << "10! = " << Silnia<10>::value << "\n";
    return 0;
}