#include <iostream>
#include <string>


class Shape {
public:
    virtual double area() = 0;
    virtual std::string name() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() override { return 3.14159 * r * r; }
    std::string name() override { return "Circle"; }
};

class Rectangle : public Shape {
    double a, b;
public:
    Rectangle(double a, double b) : a(a), b(b) {}
    double area() override { return a * b; }
    std::string name() override { return "Rectangle"; }
};


template <typename T>
void print(T& shape) {
    std::cout << shape.name() << " has area: " << shape.area() << "\n";
}


int main() {
    Shape* shapes[] = { new Circle(5), new Rectangle(3, 4) };

    std::cout << "Dynamic polymorphism\n";
    for (auto s : shapes)
        std::cout << s->name() << ": " << s->area() << "\n";

    std::cout << "\nStatic polymorphism\n";
    Circle c(7);
    Rectangle r(2, 6);
    print(c);
    print(r);

    for (auto s : shapes) delete s;
    return 0;
}
