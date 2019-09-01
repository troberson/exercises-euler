/*
 * Project Euler - Utils - recurrence
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for recurrence relations, such as Fibonacci numbers.
 */

#pragma once

#include <functional>
#include <vector>


namespace euler::utils
{

/**
 * Generate a vector from a recurrence relation which includes entries up to a given value.
 *
 * @param n the maximum value (inclusive)
 * @param fn a function to generate the next entry from the previous one
 * @param start_a the first entry of the sequence
 * @returns a vector
 */
std::vector<int> recurrence_up_to(
    int n, const std::function<int(int)>& fn, int start_a);

/**
 * Generate a vector from a recurrence relation which includes entries up to a given value.
 *
 * @param n the maximum value (inclusive)
 * @param fn a function to generate the next entry from the previous two
 * @param start_a the first entry of the sequence
 * @param start_b the second entry of the sequence
 * @returns a vector
 */
std::vector<int> recurrence_up_to(
    int n, const std::function<int(int, int)>& fn, int start_a, int start_b);

/**
 * Generate the Fibonacci sequence up to a given value.
 *
 * @param n the maximum value (inclusive)
 * @returns a vector
 */
std::vector<int> fibonacci_up_to(int n);

} // end namespace euler::utils
