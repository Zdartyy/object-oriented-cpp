#include <vector>
#include <algorithm>
#include <execution>
#include <mutex>
#include <numeric>
#include <iostream>
#include <chrono>

int main() {
    std::vector<int> vec(10'000'000); 
    std::iota(vec.begin(), vec.end(), 0); 
    
    std::vector<int> output;
    std::mutex m;

    std::cout << "Testowanie polityki równoległej (par) z lock_guard...\n";
    auto start_par = std::chrono::high_resolution_clock::now();
    
    std::for_each(std::execution::par, vec.begin(), vec.end(),
        [&output, &m](int& elem) { 
            if (elem % 2 == 0) { 
                std::lock_guard<std::mutex> lock(m);
                output.push_back(elem);
            }
        });
        
    auto end_par = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_par = end_par - start_par;
    std::cout << "Czas wykonania (par): " << diff_par.count() << " s\n";
    std::cout << "Rozmiar wektora wyjściowego (par): " << output.size() << "\n\n";

    output.clear(); // czyscimy wektor przed kolejnym testem

    std::cout << "Testowanie polityki sekwencyjnej (seq)...\n";
    auto start_seq = std::chrono::high_resolution_clock::now();
    
    std::for_each(std::execution::seq, vec.begin(), vec.end(),
        [&output](int& elem) { 
            if (elem % 2 == 0) { 
                // w wersji sekwencyjnej nie potrzebujemy muteksa
                output.push_back(elem);
            }
        });
        
    auto end_seq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_seq = end_seq - start_seq;
    std::cout << "Czas wykonania (seq): " << diff_seq.count() << " s\n";
    std::cout << "Rozmiar wektora wyjściowego (seq): " << output.size() << "\n";

    return 0;
}