#include <iostream>

template<typename From, typename To>
class Is_convertible {
    typedef char one;
    typedef struct { char c[2]; } two;

    static one test(To);
    static two test(...);

    static From makeFrom();

public:
    enum { yes = (sizeof(test(makeFrom())) == sizeof(one)) };
};

int main() {

    std::cout << Is_convertible<int, double >::yes << "\n"; // 1
    std::cout << Is_convertible<double, int >::yes << "\n"; // 1
    std::cout << Is_convertible<int, int* >::yes << "\n"; // 0
    std::cout << Is_convertible<char*, int >::yes << "\n"; // 0
    
}