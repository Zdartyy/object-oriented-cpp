#include <iostream>
#include <vector>
#include <list>
#include <set>

template <typename Iterator>
auto accumulate(Iterator first, Iterator last) {
    auto result = *first;
    ++first;
    while (first != last) {
        result += *first;
        ++first;
    }
    return result;
}

int main() {

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << "vector: " << accumulate(v.begin(), v.end()) << "\n"; // 15

    std::list<double> l = {1.1, 2.2, 3.3};
    std::cout << "list:   " << accumulate(l.begin(), l.end()) << "\n"; // 6.6

    std::set<int> s = {10, 20, 30};
    std::cout << "set:    " << accumulate(s.begin(), s.end()) << "\n"; // 60
}
