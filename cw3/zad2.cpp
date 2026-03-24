#include <iostream>

// Szablon convert — To to typ zwracany, From dedukowany z argumentu
template <typename To, typename From>
To convert(From val) {
    return static_cast<To>(val);
}

int main() {
    double x = 3.99;

    // Te dwa wywołania mają IDENTYCZNE argumenty (x),
    // ale różne typy zwracane — To=int vs To=float
    int   a = convert<int>  (x);  // zwraca int
    float b = convert<float>(x);  // zwraca float
    char  c = convert<char> (x);  // zwraca char

    std::cout << a << "\n";  // 3
    std::cout << b << "\n";  // 3.99
    std::cout << c << "\n";  // ASCII 3 (znak o kodzie 3)
}
