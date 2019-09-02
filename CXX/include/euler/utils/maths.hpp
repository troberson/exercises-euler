/*
 * Project Euler - Utils - maths
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Miscellaneous maths functions.
 */

#pragma once

#include "template_types.hpp"

#include <cmath> // std::abs
#include <numeric> // std::accumulate, std::iota
#include <vector> // std::vector


namespace euler::utils
{

/**
 * Greatest common divisor
 *
 * @note
 * There is an STL function std::gcd in <numeric>.
 * This function is for educational purposes.
 *
 * @note
 * Mathematically, `gcd(0,0)` is undefined.
 * However, rather than throw an exception, this function
 * simply returns 0.
 *
 * @param a an integral
 * @param b an integral
 * @returns the greatest common divisor of the two numbers
 */
template <typename T, typename = IsIntegral<T>>
T gcd(T a, T b)
{
    if (b == 0)
    {
        return a;
    }

    // gcd for negative values is the same as for the positive
    // finding the absolute value of the values here ensure that
    // we do not break at -1 instead of 1.
    a = std::abs(a);
    b = std::abs(b);

    return gcd(b, a % b);
}

/**
 * Least common multiple
 *
 * There is an STL function std::lcm in <numeric>.
 * This function is for educational purposes.
 *
 * @param a an integral
 * @param b an integral
 * @returns the least common multiple of the two numbers
 */
template <typename T, typename = IsIntegral<T>>
T lcm(T a, T b)
{
    if (a == 0 && b == 0)
    {
        return 0;
    }

    T divisor = gcd(a, b);

    if (divisor == 0)
    {
        return 0;
    }

    return a * (b / divisor);
}


/**
 * Least common multiple of a list of numbers
 *
 * @param nums a vector of integrals
 * @returns the least common multiple of the list of numbers
 */
template <typename T, typename = IsIntegral<T>>
T lcmList(std::vector<T> nums)
{
    return std::accumulate(nums.begin(), nums.end(), 1, lcm<T>);
}


/**
 * Least common multiple of a range of numbers
 *
 * @param start the starting integral
 * @param end the ending integral (inclusive)
 * @returns the least common multiple of the range of numbers
 */
template <typename T, typename = IsIntegral<T>>
T lcmRange(T start, T end)
{
    std::vector<T> nums(end - start + 1);
    std::iota(nums.begin(), nums.end(), start);

    return lcmList(nums);
}


/**
 * Product of a vector.
 *
 * @param a vector of numbers
 * @returns the product
 */
template <
    typename T, typename U,
    typename = IsArithmetic<T>, typename = IsArithmetic<U>>
T product(std::vector<U> vect)
{
    return std::accumulate(vect.begin(), vect.end(), static_cast<T>(1), std::multiplies<>());
}

} // end namespace euler::utils

