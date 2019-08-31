/*
 * Project Euler - Utils - maths
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Miscellaneous maths functions.
 */

#pragma once

#include "template_types.hpp"

#include <numeric> // std::accumulate, std::iota
#include <vector> // std::vector


/**
 * Greatest common divisor
 *
 * There is an STL function std::gcd in <numeric>.
 * This function is for educational purposes.
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
    return a * (b / gcd(a, b));
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
