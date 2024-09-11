#ifndef sum_generic_cpp
#define sum_generic_cpp

#include "sum_generic.hpp"

template <typename T>
T sum (T x, T y)
{
    return x + y;
}

template <typename T>
T sum (T x,T y,T z)
{
    return x + y + z;
}

#endif