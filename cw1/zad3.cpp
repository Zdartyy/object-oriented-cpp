#include <iostream>

template <typename T, int N>

T dot_product(T a[N], T b[N]) {
    T result = 0;
    for (int i = 0; i < N; i++) {
        result += a[i] * b[i];
    }
    return result;
}

int main() {
    int a[] = {1, 3, 9};
    int b[] = {3, 5, 6};
    std::cout << dot_product<int, 3>(a, b) << "\n";
}