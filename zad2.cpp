#include <iostream>

template <typename To, typename From>

To convert(From val) {
    return static_cast<To>(val);
}


int main() {
    std::cout << convert<int>(21.37) << "\n";
    std::cout << convert<char>(67) << "\n";
}