#include <iostream>
#include <memory>

int main() {

    std::cout << "sizeof(int*) = " << sizeof(int*) << "\n";
    std::cout << "sizeof(unique_ptr<int>) = " << sizeof(std::unique_ptr<int>) << "\n";
    std::cout << "sizeof(shared_ptr<int>) = " << sizeof(std::shared_ptr<int>) << "\n";
    std::cout << "sizeof(weak_ptr<int>) = " << sizeof(std::weak_ptr<int>) << "\n";

    return 0;
}

// std::unique_ptr ma taki sam rozmiar jak zwykły wskaźnik.
// std::shared_ptr oraz std::weak_ptr są dwukrotnie większe 
// od zwykłego wskaźnika (bo przechowują dodatkowe informacje, 
// np licznik referencji).