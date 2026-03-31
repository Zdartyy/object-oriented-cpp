#include <iostream>
#include <cstring>
#include "sum_traits.h"


template<typename T>
typename sum_traits<T>::sum_type sum(T* beg, T* end) {
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_traits<T>::zero();
    while (beg != end) { total += *beg; ++beg; }
    return total;
}

int main() {
    char name[] = "@ @ @";
    std::cout << sum(name, name + strlen(name)) << "\n";

    int arr[] = {1, 2, 3};
    std::cout << sum(arr, arr + 3) << "\n";

    double darr[] = {1.5, 2.5, 3.5};
    std::cout << sum(darr, darr + 3) << "\n";
}