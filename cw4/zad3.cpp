#include <iostream>
#include <cstring>
#include "sum_traits.h"
#include "char_sum.h"


template<typename Traits, typename T>
typename Traits::sum_type sum(T* beg, T* end) {
    typedef typename Traits::sum_type sum_type;
    sum_type total = Traits::zero();
    while (beg != end) { total += *beg; ++beg; }
    return total;
}

template<typename T>
typename sum_traits<T>::sum_type sum(T* beg, T* end) {
    return sum<sum_traits<T>, T>(beg, end);
}

int main() {
    char name[] = "@ @ @";
    int n = strlen(name);

    auto wynik1 = sum(name, name + n);
    std::cout << wynik1 << "\n";

    int arr[] = {1, 2, 3};
    auto wynik2 = sum(arr, arr + 3);
    std::cout << wynik2 << "\n";

    double darr[] = {1.5, 2.5, 3.5};
    auto wynik3 = sum(darr, darr + 3);
    std::cout << wynik3 << "\n";

    auto wynik4 = sum<char_sum>(name, name + n);
    std::cout << (int)wynik4 << "\n";
}