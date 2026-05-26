1. `std::execution::sequenced_policy` : Algorytm wykonuje się sekwencyjnie w pojedynczym wątku. Działa przewidywalnie i nie wymaga synchronizacji

2. `std::execution::parallel_policy` : Algorytm jest zrównoleglony na wielu wątkach. Zapewnia potencjalne przyspieszenie w zależności od liczby rdzeni procesora, lecz wymaga synchronizacji, gdy współdzielone są zasoby.

3. `std::execution::parallel_unsequenced_policy` : Wykonanie jest zrównoleglone i może być wektoryzowane (SIMD). Narzuca na nas ścisłe restrykcje, np. użycie `std::mutex` wewnątrz algorytmu jest niedozwolone, ponieważ powoduje deadlocki
