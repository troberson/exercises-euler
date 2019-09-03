/*
 * Project Euler - 009 - Special Pythagorean triplet
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c,
 * for which,
 *
 *      a^2 + b^2 = c^2
 *
 * For example,
 *
 *      3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *
 * Find the product abc.
 */

/*
 * NOTE:
 * A basic method for finding Pythagorean triplets is with the formula:
 *
 *      a = r^2 - s^2
 *      b = 2rs
 *      c = r^2 + s^2
 *      r > s > 0 are whole numbers
 *      r - s is odd
 *
 * For primitive Pythagorean triplets:
 *
 *      the greatest common divisor of r and s is 1.
 *
 *  (http://mathforum.org/dr.math/faq/faq.pythag.triples.html)
 */

#include <euler/euler009.hpp>
#include <euler/utils/maths.hpp> // utils::generate_pythagorean_triplet

#include <cmath> // std::sqrt
#include <cstdint> // int64_t
#include <vector> // std::vector

#include <iostream>

namespace euler
{

std::vector<int> find_pythagorean_triplet_with_sum(int sum)
{
    // We can simplify the Pythagorean triplet formula:
    //
    //  (a, b, c) = (m^2 - n^2, 2mn, m^2 + n^2)
    //        sum = a + b + c
    //        sum = m^2 - n^2 + 2mn + m^2 + n^2
    //        sum = m^2 + 2mn + m^2
    //        sum = 2(m^2 + mn)
    //        sum = 2m(m + n)
    //    sum / 2 = m(m + n)
    // sum / (2m) = m + n
    //          n = sum / (2m) - m

    // Only even sums have solutions
    if (sum % 2 == 1)
    {
        return {};
    }

    // Take half the sum
    int sum_half = sum / 2;

    // The maximum value of m is such that n > 0:
    // sum / (2m) - m = n = 0
    //     sum / (2m) = m
    //        sum / 2 = m^2
    //              m = sqrt(sum/2)
    int m = static_cast<int>(std::sqrt(sum_half));
    for (; m > 2; m--)
    {
        // if sum_half is divisible by m,
        // we have found an integer solution
        if (sum_half % m == 0)
        {
            break;
        }
   }

    // Return empty vector if no solution found
    if (m == 0)
    {
        return {};
    }

    // Find n
    int n = sum_half / m - m;

    // Generate the triplet
    auto triplet = utils::generate_pythagorean_triplet<int>(m, n);

    // Return triplet
    return triplet;
}


int64_t euler009()
{
    auto triplet = find_pythagorean_triplet_with_sum(1000);
    return utils::product<int64_t>(triplet);
}

} // end namespace euler
