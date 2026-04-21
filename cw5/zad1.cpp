#include <iostream>

template<typename T>
class Is_class {
    typedef char one;
    typedef struct { char c[2]; } two;

    template<typename U> static one test(int U::*);
    template<typename U> static two test(...);

public:
    enum { yes = (sizeof(test<T>(0)) == sizeof(one)) };
};

struct MojaKlasa {};

int main() {

    std::cout << Is_class<MojaKlasa>::yes << "\n"; // 1 klasa
    std::cout << Is_class<int>::yes << "\n"; // 0 nie klasa
    std::cout << Is_class<double>::yes << "\n"; // 0 nie klasa

}