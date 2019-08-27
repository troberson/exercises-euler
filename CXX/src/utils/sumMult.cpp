/*
 * Project Euler - Utils - sumMult
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Returns the sum of a series of integers which are muliples of a number
 */

/*
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
