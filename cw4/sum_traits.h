#pragma once


template<typename T>
struct sum_traits {
    typedef T sum_type;
    static sum_type zero() { return T(); }
};

template<> struct sum_traits<char> {
    typedef int sum_type;
    static sum_type zero() { return 0; }
};

template<> struct sum_traits<int> {
    typedef long int sum_type;
    static sum_type zero() { return 0; }
};

template<> struct sum_traits<float> {
    typedef double sum_type;
    static sum_type zero() { return 0.0; }
};

template<> struct sum_traits<double> {
    typedef double sum_type;
    static sum_type zero() { return 0.0; }
};