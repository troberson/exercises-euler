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

#include <cstdint> // int64_t
#include <vector> // std::vector

namespace euler
{

/**
 * Find a Pythagorean triplet with a given sum
 *
 * A Pythagorean triplet is `(a, b, c)` such that
 * @rst
 * :math:`a^2 + b^2 = c^2`
 * @endrst
 *
 * @param sum the sum to find
 * @returns a list of three numbers or an empty list if no triplet found
 */
std::vector<int> find_pythagorean_triplet_with_sum(int sum);


/**
 * Solves the problem.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 *
 * @returns the solution to the problem
 */
int64_t euler009();


} // end namespace euler
