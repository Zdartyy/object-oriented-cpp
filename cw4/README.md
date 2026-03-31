# Zaawansowane techniki programowania obiektowego w C++

## Zestaw nr 4

1. Zaimplementuj szablon funkcji sumującej elementy dla podanego zakresu wskaźników. Przygotowując odpowiednie klasy cech sum_traits dla każdego z typów (char, int, float, double) zadbaj o poprawność typu zmiennej total, która w szablonie sum przechowuje wartość kolejnych kroków sumowania.

2. Rozwiązać za pomocą klas cech również problem inicjalizacji zmiennej total.

3. Szablony funkcji nie dopuszczają stosowania parametrów domyślnych. Można to ograniczenie obejść za pomocą przeciążenia szablonu definiując szablon o mniejszej ilości argumentów, który zwraca wynik podstawienia domyślnych parametrów do bardziej ogólnego szablonu. Zmienić implementację funkcji sum tak aby podając odpowiednią klasę cech (sum_char) jako pierwszy z argumentów szablonu można było zażądać sumowania znaków char do zmiennej total również typu char. Równocześnie, w przypadku gdy nie jest podana klasa cech, szablon powinien działać tak jak w zad. 2.
