#include <iostream>
#include <cstring>
#include <cstddef>

template <typename T>
T max(T a, T b) {
    return (a < b) ? b : a;
}


template <typename T>
T* max(T* a, T* b) {
    return (*a < *b) ? b : a;
}

template <typename T>
T* max(T* data, size_t n) {
    T* result = data;
    for (size_t i = 1; i < n; i++)
        if (result[i] > *result)
            result = &data[i];
    return result;
}

template <>
char* max<char*>(char* a, char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

template <>
const char* max<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

const char* max(char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}


int main() {

    std::cout << max(3, 7) << "\n";
    std::cout << max(3.14, 2.71) << "\n";

    int x = 3, y = 7;
    std::cout << *max(&x, &y) << "\n";

    int arr[] = {3, 1, 7, 2, 5};
    std::cout << *max(arr, (size_t)5) << "\n";

    char a[] = "hello", b[] = "world";
    std::cout << max(a, b) << "\n";

    const char* ca = "hello";
    const char* cb = "world";
    std::cout << max(ca, cb) << "\n";

    std::cout << max(a, cb) << "\n";
}
