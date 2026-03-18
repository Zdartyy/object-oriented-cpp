#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


class SequenceGen {
    int current;
public:
    SequenceGen(int start = 1) : current(start) {}

    int operator()() {
        int val = current;
        current += 2;
        return val;
    }
};

int main() {
    std::vector<int> v;
    v.resize(20);

    std::generate_n(v.begin(), 20, SequenceGen());

    std::cout << "Wektor: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    auto it = std::find_if(v.begin(), v.end(),
                  std::bind2nd(std::greater<int>(), 4));

    if (it != v.end())
        std::cout << "Pierwszy element > 4: " << *it << "\n";
}
