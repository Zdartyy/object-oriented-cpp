#include <iostream>
#include <cstring>


template<typename T>
struct sum_traits;

template<>
struct sum_traits<char> {
    typedef int sum_type;
    static sum_type zero() { return 0; }
};

template<>
struct sum_traits<int> {
    typedef long int sum_type;
    static sum_type zero() { return 0; }
};

template<>
struct sum_traits<float> {
    typedef double sum_type;
    static sum_type zero() { return 0.0; }
};

template<>
struct sum_traits<double> {
    typedef double sum_type;
    static sum_type zero() { return 0.0; }
};


template<typename T>
typename sum_traits<T>::sum_type sum(T* beg, T* end) {
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_traits<T>::zero();
    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}

int main() {

    char name[] = "@ @ @";
    int length = strlen(name);
    std::cout << sum(name, name + length) << "\n";

    int arr[] = {1000000, 2000000, 3000000};
    std::cout << sum(arr, arr + 3) << "\n";

    float farr[] = {1.1f, 2.2f, 3.3f};
    std::cout << sum(farr, farr + 3) << "\n";

    double darr[] = {1.5, 2.5, 3.5};
    std::cout << sum(darr, darr + 3) << "\n";
}