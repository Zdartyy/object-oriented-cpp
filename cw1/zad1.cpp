#include <iostream>

template <typename T> 
T max(T a, T b) {
    return (a < b) ? b : a;
}

int main() {
    std::cout << max(3, 7) << "\n";
    std::cout << max(3.15, 7.2) << "\n";
    std::cout << max('a', 'g') << "\n";
}