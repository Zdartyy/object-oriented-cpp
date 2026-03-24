#include <iostream>
#include <cstring>



template <typename T, int N>
class Stack {
public:
    void info() {
        std::cout << "Stack<T, N> — ogolny\n";
    }
};

template <typename T>
class Stack<T, 666> {
public:
    void info() {
        std::cout << "Stack<T, 666> — specjalny rozmiar 666\n";
    }
};

template <typename T, int N>
class Stack<T*, N> {
public:
    void info() {
        std::cout << "Stack<T*, N> — dowolny wskaznik\n";
    }
};

template <int N>
class Stack<double, N> {
public:
    void info() {
        std::cout << "Stack<double, N> — double, dowolny rozmiar\n";
    }
};

template <int N>
class Stack<int*, N> {
public:
    void info() {
        std::cout << "Stack<int*, N> — wskaznik na int\n";
    }
};

template <>
class Stack<double, 666> {
public:
    void info() {
        std::cout << "Stack<double, 666> — pelna specjalizacja\n";
    }
};

template <>
class Stack<double*, 44> {
public:
    void info() {
        std::cout << "Stack<double*, 44> — pelna specjalizacja\n";
    }
};

int main() {
    Stack<int, 10> s1; s1.info();
    Stack<int, 666> s2; s2.info();
    Stack<int*, 5> s3; s3.info();
    Stack<double, 5> s4; s4.info();
    Stack<int*, 10> s5; s5.info();
    Stack<double, 666> s6; s6.info();
    Stack<double*, 44> s7; s7.info();
}
