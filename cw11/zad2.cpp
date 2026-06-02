#include <compare>
#include <iostream>
#include <string>
#include <vector>

/*
 * Koncept std::three_way_comparable sprawdza, czy dany typ wspiera operator <=> 
 * i czy wynik tego porównania można przyrównać do zera (np. wynik < 0, == 0, > 0).
 */


// Klasa nie wspierajaca operatora <=>
struct NoSpaceship {
    int value;
};

// Klasa wspierajaca operator <=>
struct WithSpaceship {
    int value;
    auto operator<=>(const WithSpaceship&) const = default;
};

int main() {
    std::cout << std::boolalpha << "\n";

    // int, double, string, vector<int> spelniaja koncept
    static_assert(std::three_way_comparable<int>);
    static_assert(std::three_way_comparable<double>);
    static_assert(std::three_way_comparable<std::string>);
    static_assert(std::three_way_comparable<std::vector<int>>);

    // NoSpaceship nie spelnia konceptu
    static_assert(!std::three_way_comparable<NoSpaceship>);

    // WithSpaceship spelnia koncept dzieki operator<=> = default
    static_assert(std::three_way_comparable<WithSpaceship>);

    std::cout << "Sprawdzenie w czasie kompilacji (static_assert)\n";
    std::cout << "Wszystkie static_assert przeszly pomyslnie.\n\n";

    std::cout << "Sprawdzenie w czasie wykonania\n";
    std::cout << "std::three_way_comparable<int>: " << std::three_way_comparable<int> << "\n";
    std::cout << "std::three_way_comparable<double>: " << std::three_way_comparable<double> << "\n";
    std::cout << "std::three_way_comparable<std::string>: " << std::three_way_comparable<std::string> << "\n";
    std::cout << "std::three_way_comparable<NoSpaceship>: " << std::three_way_comparable<NoSpaceship> << "\n";
    std::cout << "std::three_way_comparable<WithSpaceship>:" << std::three_way_comparable<WithSpaceship> << "\n\n";


    auto describe = []<typename T>(T a, T b) {
        if constexpr (std::three_way_comparable<T>) {
            auto result = a <=> b;
            if (result < 0) std::cout << "a < b\n";
            else if (result > 0) std::cout << "a > b\n";
            else std::cout << "a == b\n";
        } else {
            std::cout << "Typ nie wspiera operatora <=>\n";
        }
    };

    std::cout << "Uzycie operatora <=>\n";
    std::cout << "int 3 vs 5: "; describe(3, 5);
    std::cout << "int 7 vs 2: "; describe(7, 2);
    std::cout << "double 1.5 vs 1.5: "; describe(1.5, 1.5);

    std::cout << "string 'abc' vs 'abd': ";
    describe(std::string("abc"), std::string("abd"));

    WithSpaceship x{10}, y{20};
    std::cout << "WithSpaceship 10 vs 20: "; describe(x, y);

    return 0;
}
// Kompilacja: g++ -std=c++20 zad2.cpp -o zad2 && ./zad2