#include <iostream>
#include <vector>

template<typename T>
class has_value_type {
    typedef char one;
    typedef struct { char c[2]; } two;

    template<typename U> static one test(typename U::value_type*);
    template<typename U> static two test(...);

public:
    enum { yes = (sizeof(test<T>(0)) == sizeof(one)) };
};

int main() {

    std::cout << has_value_type<std::vector<int>>::yes << "\n"; // 1
    std::cout << has_value_type<int>::yes << "\n"; // 0
    std::cout << has_value_type<std::string>::yes << "\n"; // 1
    
}