#include <algorithm>
#include <execution>
#include <vector>
#include <numeric>
#include <iostream>

int main() {
    std::vector<int> v(10'000'000);
    std::iota(v.begin(), v.end(), 0);

    std::sort(std::execution::par, v.begin(), v.end());

    std::cout << v.back() << "\n";
}