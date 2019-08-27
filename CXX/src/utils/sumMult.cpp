/*
 * Project Euler - Utils - sumMult
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Returns the sum of a series of integers which are muliples of a number
 */

/*
 * The brute-force method would be to list all the numbers under 1000 which
 * are multiples of 3, sum those, add those which are multiples of 5, and
 * subtract those which are multiples of 15.
 *
 * However, we can also use the method attributed to the child Gauss for
 * finding the sum of a series of natural numbers: n(n-1)/2. So, for example,
 * the sum of the numbers 1 to 100 are 100*101/2 = 5050.
 *
 * The set of numbers under 1000 divisible by 3 can be described as
 * { 3n | for 0 <= n < floor(999/2) } so therefore the sum of the numbers
 * under 1000 divisible by 3 is 3*333*334/2, for 5, it is
 * 5*199*20=0/5, and for 15, 15*66*67/2.
 */

#include <euler/utils/sumMult.hpp>


/**
 * Sum the integers between 0 and the given max (exclusive)
 * which are multiples of `step`.
 *
 * Example:
 *
 *     sumMult(10, 2)
 *
 * This returns 20 because 2 + 4 + 6 + 8 = 20.
 *
 * @param max the maximum (exclusive) number to include in the sum
 * @param step include integers which are multiples of `step`
 * @returns sum of integers
 */
unsigned int sumMult(unsigned int max, unsigned int step)
{
  int n = (max - 1) / step;
  return step * n * (n + 1) / 2;
}


/**
 * Sum the integers between 0 and the given max (exclusive)
 * which are multiples of either `step_a` or `step_b`.
 *
 * Example:
 *
 *     sumMult(10, 2, 3)
 *
 * This returns 32 because:
 * 2 + 4 + 6 + 8 = 20
 * 3 + 6 + 9 = 18
 * 20 + 18 - 6 (factor of both 2 and 3) = 32
 *
 * @param max the maximum (exclusive) number to include in the sum
 * @param step_a include integers which are multiples of `step_a`
 * @param step_b include integers which are multiples of `step_a`
 * @returns sum of integers
 */
unsigned int sumMult(unsigned int max, unsigned int step_a, int step_b)
{
  return sumMult(max, step_a) + sumMult(max, step_b) - sumMult(max, step_a * step_b);
}

