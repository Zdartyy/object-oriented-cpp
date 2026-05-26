#include <algorithm>
#include <execution>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {5, 3, 1, 4, 2};

    std::sort(std::execution::seq, v.begin(), v.end());

    for (int x : v) std::cout << x << " ";
}