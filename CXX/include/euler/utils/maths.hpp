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
#include <limits> // std::numeric_limits
#include <numeric> // std::accumulate, std::iota
#include <stdexcept> // std::domain_error
#include <vector> // std::vector


namespace euler::utils
{

/**
 * Greatest common divisor
 *
 * @note
 * There is an STL function `std::gcd`.
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
 * There is an STL function `std::lcm`.
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
 * @param vect a vector of numbers
 * @returns the product
 */
template <
    typename T, typename U,
    typename = IsArithmetic<T>, typename = IsArithmetic<U>>
T product(std::vector<U> vect)
{
    return std::accumulate(vect.begin(), vect.end(), static_cast<T>(1), std::multiplies<>());
}


/**
 * Generate Pythagorean triplet
 *
 * @rst
 * The Pythagorean theorem describes the three sides of a right triangle
 * with the relation :math:`a^2 + b^2 = c^2`, where `a` and `b` are the
 * lengths of the sides and `c` is length of the the hypotenuse. The natural
 * numbers which can satify this relationship are known as Pythagorean
 * triplets.
 *
 * Pythagorean triplets can be generated with the relation
 *
 * .. math::
 *   (a,\:b,\:c) = (m^2 - n^2,\:2mn,\:m^2 + n^2)
 *
 * where `m` and `n` are natural numbers such that :math:`m > n`.
 *
 * .. warning::
 *   `m` and `n` must be nonzero natural numbers such that :math:`m > n`.
 *   Otherwise, will throw a `std::domain_error` exception. The template
 *   parameter `T` should usually be at least as large as `U` in order to
 *   avoid overflows.
 * @endrst
 *
 * @tparam T the type of the output values
 * @tparam U the type of the input values
 * @param m a natural number greater than `n`
 * @param n a natural number less than `m`
 * @return a Pythagorean triplet
 * @throw std::domain_error if not `m > n > 0`
 * @throw std::range_error on overflow
 */
template <
    typename T, typename U,
    typename = IsIntegral<T>, typename = IsIntegral<U>>
std::vector<T> generate_pythagorean_triplet(U m, U n)
{
    // Precondition: the parameters must be greater than zero
    if (m < 1 || n < 1)
    {
        throw std::domain_error(
            "parameters must be nonzero natural numbers");
    }

    // Precondition: the first parameter must be greater than the second
    if (m <= n)
    {
        throw std::domain_error(
            "the first parameter must be greater than the second");
    }

    // Convert the inputs to the output type to avoid overflow
    m = T(m);
    n = T(n);

    // Check for potential overflows
    // the largest possible value here is
    // 2 * m * (m - 1)
    T output_limit = std::numeric_limits<T>::max();
    if ((output_limit / m) / 2 < m - 1)
    {
        throw std::range_error("the output type is not large enough");
    }

    // Formula:
    // (a, b, c) = (m^2 - n^2, 2mn, m^2 + n^2)
    T a = m * m - n * n;
    T b = 2 * m * n;
    T c = m * m + n * n;

    return { a, b, c };
}

} // end namespace euler::utils
