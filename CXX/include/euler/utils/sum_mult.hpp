/*
 * Project Euler - Utils - sum_mult
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Returns the sum of a series of integers which are muliples of a number
 */

#pragma once


/**
 * Sum the integers between 0 and the given max (exclusive)
 * which are multiples of `step`.
 *
 * @rst
 * **Example:** `sum_mult(10, 2)`
 *
 * This returns 20 because the sum of multiples of 2 between 0 and
 * 10 are :math:`2 + 4 + 6 + 8 = 20`.
 * @endrst
 *
 * @param max the maximum (exclusive) number to include in the sum
 * @param step include integers which are multiples of `step`
 * @returns sum of integers
 */
unsigned int sum_mult(unsigned int max, unsigned int step);


/**
 * Sum the integers between 0 and the given max (exclusive)
 * which are multiples of either `step_a` or `step_b`.
 * @rst
 * **Example**: `sum_mult(10, 2, 3)`
 *
 * This returns 32 because:
 *
 * .. math::
 *     2 +  4 + 6 + 8 & = 20 \text{ (sum of multiples of 2 between 0 and 10)}\\
 *     3 +  6 + 9     & = 18 \text{ (sum of multiples of 3 between 0 and 10)}\\
 *    20 + 18 - 6     & = 32 \text{ (add the sums and subtract 6, which is a factor of both)}
 * @endrst
 *
 * @param max the maximum (exclusive) number to include in the sum
 * @param step_a include integers which are multiples of `step_a`
 * @param step_b include integers which are multiples of `step_a`
 * @returns sum of integers
 */
unsigned int sum_mult(unsigned int max, unsigned int step_a, int step_b);
