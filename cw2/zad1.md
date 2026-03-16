# Polimorfizm statyczny

Mechanizm, w którym wybór odpowiedniej funkcji następuje w **czasie kompilacji**.
W C++ realizowany przez przeciążanie funkcji oraz szablony.
Kompilator na podstawie typów argumentów sam decyduje, którą wersję wywołać.

# Polimorfizm dynamiczny

Mechanizm, w którym wybór odpowiedniej metody następuje w **czasie wykonania programu**,
na podstawie rzeczywistego typu obiektu. W C++ realizowany przez funkcje wirtualne
i dziedziczenie. Umożliwia wywoływanie właściwej metody przez wskaźnik lub referencję
do klasy bazowej.

# Funkcja wirtualna

Metoda klasy oznaczona słowem kluczowym `virtual`, która może zostać **nadpisana**
(`override`) w klasie pochodnej. Zapewnia polimorfizm dynamiczny — przy wywołaniu
przez wskaźnik bazowy, program w czasie wykonania sprawdza rzeczywisty typ obiektu
i wywołuje właściwą implementację.
Czysta funkcja wirtualna (`= 0`) nie posiada implementacji w klasie bazowej
i **musi** być nadpisana w klasach pochodnych.

# Klasa abstrakcyjna

Klasa zawierająca co najmniej jedną czystą funkcję wirtualną (`= 0`).
Nie można tworzyć jej instancji bezpośrednio — służy jako **interfejs/kontrakt**
dla klas pochodnych, które muszą dostarczyć implementacje wszystkich czystych
funkcji wirtualnych.

---

## Przykład

```cpp
class Figura {                              // klasa abstrakcyjna
public:
    virtual double pole() = 0;             // czysta funkcja wirtualna
};

class Kolo : public Figura {
    double r;
public:
    Kolo(double r) : r(r) {}
    double pole() override { return 3.14 * r * r; } // nadpisanie
};

int main() {
    Figura* f = new Kolo(5);
    f->pole(); // polimorfizm dynamiczny — runtime wywołuje Kolo::pole()
}
```
