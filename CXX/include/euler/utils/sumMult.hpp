/*
 * Project Euler - Utils - sumMult
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
unsigned int sumMult(unsigned int max, unsigned int step);


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
unsigned int sumMult(unsigned int max, unsigned int step_a, int step_b);
