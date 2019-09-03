/*
 * Project Euler - Utils - sum
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Sum a range of integers, optionally only those which are the muliples of a
 * number.
 * -----
 *
 * These methods use strategy attributed to the child Gauss for finding the
 * sum of a series of natural numbers: n(n-1)/2. So, for example, the sum of
 * the numbers 1 to 100 are 100*101/2 = 5050.
 *
 * To sum only multiples of a particular number, we divide the maximum number,
 * n, by the number we want to use multiples of, or 'step', (we only need the
 * integer floor) and we use this number, call it n', in place of n.
 * Multiplying the step by the new equation n'(n'-1)/2 gives us the sum.
 *
 * To sum only multiples of two different numbers, we find the sum as above for
 * each step individually, then find the sum using the product of the two sums.
 * Adding the two step sums and subtracting the product sum gives us the final
 * total. If we wanted to include additional steps, we would follow the
 * Principle of Inclusion-Exclusion and alternately subtract and add sums as
 * required.
 */

#pragma once

#include "template_types.hpp"

#include <cmath> // std::abs
#include <numeric> // std::accumulate
#include <vector> // std::vector


namespace euler::utils
{


/**
 * Sum the integers between 0 and the given max (inclusive)
 * which are multiples of `step`.
 *
 * @rst
 * **Example:** `sum_mult(9, 2)`
 *
 * This returns 20 because the sum of multiples of 2 between 0 and
 * 10 are :math:`2 + 4 + 6 + 8 = 20`.
 * @endrst
 *
 * @note
 *   Providing a negative number for the maximum will calculate the result
 *   for that number up to 0 (the negation of the positive sum).
 *
 * @param max the maximum (inclusive) number to include in the sum
 * @param step include integers which are multiples of `step`
 * @returns sum of integers
 */
template <
    typename T, typename U,
    typename = IsIntegral<T>, typename = IsIntegral<U>>
T sum_mult(T max, U step)
{
    // The sum of negative numbers up to 0 is the
    // same as 0 up to that number, except negative.
    // Making these absolute avoids issues with the
    // arithmetic in the formula.
    bool is_neg = max < 0;
    max = std::abs(max);
    step = std::abs(step);

    // Gauss's formula
    //   Sn = n(n-1)/2
    int n = max / step;
    T result = step * n * (n + 1) / 2;

    // Return either the positive or negative result
    return is_neg ? -result : result;
}


/**
 * Sum the integers between 0 and the given max (inclusive) which are
 * multiples of either `step_a` or `step_b` but not both.
 *
 * @rst
 * **Example**: `sum_mult(9, 2, 3)`
 *
 * This returns 32 because:
 *
 * .. math::
 *     2 +  4 + 6 + 8 & = 20 \text{ (sum of multiples of 2 between 0 and 9)}\\
 *     3 +  6 + 9     & = 18 \text{ (sum of multiples of 3 between 0 and 9)}\\
 *    20 + 18 - 6     & = 32 \text{ (add the sums and subtract 6, which is a factor of both)}
 * @endrst
 *
 * @note
 *   Providing a negative number for the maximum will calculate the result
 *   for that number up to 0 (the negation of the positive sum).
 *
 * @param max the maximum (inclusive) number to include in the sum
 * @param step_a include integers which are multiples of `step_a`
 * @param step_b include integers which are multiples of `step_a`
 * @returns sum of integers
 */
template <
    typename T, typename U,
    typename = IsIntegral<T>, typename = IsIntegral<U>>
T sum_mult(T max, U step_a, U step_b)
{
  return sum_mult(max, step_a) + sum_mult(max, step_b) - sum_mult(max, step_a * step_b);
}


/**
 * Sum the integers between 0 and the given max (inclusive)
 *
 * @note
 *   Providing a negative number for the maximum will calculate the result
 *   for that number up to 0 (the negation of the positive sum).
 *
 * @param max the maximum (inclusive) number to include in the sum
 * @returns sum of integers
 */
template <typename T, typename = IsIntegral<T>>
T sum(T max)
{
    return sum_mult(max, 1);
}


/**
 * Sum a vector of numbers
 *
 * @tparam T the output type
 * @tparam U the input type
 * @param vect a vector of numbers
 * @returns sum of numbers
 */
template <
    typename T, typename U,
    typename = IsArithmetic<T>, typename = IsArithmetic<U>>
T sum(std::vector<U> vect)
{
    return std::accumulate(vect.begin(), vect.end(),
        static_cast<T>(0), std::plus<>());
}

/**
 * Sum of squares
 *
 * Square all the natural numbers from 1 to `max` and find the sum.
 *
 * @param max the maximum (inclusive) number to include in the sum
 * @returns sum of squares
 */
template <typename T, typename = IsIntegral<T>>
T sum_of_squares(T max)
{
    // We're not actually squaring each number,
    // which would make all positive, so we need
    // to ensure we have a positive number for the
    // formula.
    max = std::abs(max);

    // This uses the forumula
    //     Sn = n(n + 1)(2n + 1)(1/6)
    return (max * (max + 1) * (2 * max + 1))/6;
}

} // end namespace euler::utils
