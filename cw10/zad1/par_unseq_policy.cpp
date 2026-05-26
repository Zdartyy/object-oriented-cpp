#include <algorithm>
#include <execution>
#include <vector>

int main() {
    std::vector<double> v(10'000'000, 1.5);

    std::transform(std::execution::par_unseq,
                   v.begin(), v.end(), v.begin(),
                   [](double x) { return x * 2.0; });

}