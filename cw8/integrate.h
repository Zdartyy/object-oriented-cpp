#pragma once

template<typename Functor>
double integrate(const Functor& f, double a, double b, double dx) {
    double result = 0.0;
    for (double x = a; x < b; x += dx)
        result += f(x) * dx;
    return result;
}