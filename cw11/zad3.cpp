#include <concepts>
#include <iostream>
#include <vector>

// Klasa z usunietym konstruktorem kopiujacym nie spelnia std::copyable
struct NotCopyable {
    NotCopyable() = default;
    NotCopyable(const NotCopyable&) = delete;
    NotCopyable& operator=(const NotCopyable&) = delete;
};

// Klasa kopiowalna spelnia std::copyable
struct Copyable {
    int value;
    Copyable(int v) : value(v) {}
};


template<typename T>
struct MyVector {
    std::vector<T> data;

    void push_back(const T& elem) requires std::copyable<T> {
        data.push_back(elem);
    }

    void print() const {
        for (const auto& e : data)
            std::cout << e.value << " ";
        std::cout << "\n";
    }
};

int main() {

    MyVector<Copyable> myVec1;
    myVec1.push_back(Copyable{10});
    myVec1.push_back(Copyable{20});
    myVec1.push_back(Copyable{30});

    std::cout << "MyVector<Copyable>: ";
    myVec1.print();

    // Bład przy odkomentowaniu linii:

    // MyVector<NotCopyable> myVec2;
    // myVec2.push_back(NotCopyable());


    std::cout << "\nBlad kompilacji dla NotCopyable jest zakomentowany.\n";

    return 0;
}

// Kompilacja : g++ -std=c++20 zad3.cpp -o zad3 && ./zad3