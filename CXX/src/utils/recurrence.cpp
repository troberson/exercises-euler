/*
 * Project Euler - Utils - recurrence
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for recurrence relations, such as Fibonacci numbers.
 */

#include <euler/utils/recurrence.hpp>

#include <vector>
#include <numeric>
#include <functional>


/**
 * Generate a vector from a recurrence relation which includes entries up to a given value.
 *
 * @param n the maximum value (inclusive)
 * @param fn a function to generate the next entry from the previous one
 * @param start_a the first entry of the sequence
 * @returns a vector
 */
std::vector<int> recurrenceUpTo(int n, std::function<int(int)> fn, int start_a)
{
    std::vector<int> v;

    v.push_back(start_a);

    while (true) {
        auto next = fn(v.back());
        if (next > n) {
            break;
        }
        v.push_back(next);
    }

    return v;
}

/**
 * Generate a vector from a recurrence relation which includes entries up to a given value.
 *
 * @param n the maximum value (inclusive)
 * @param fn a function to generate the next entry from the previous two
 * @param start_a the first entry of the sequence
 * @param start_b the second entry of the sequence
 * @returns a vector
 */
std::vector<int> recurrenceUpTo(
    int n, std::function<int(int, int)> fn, int start_a, int start_b)
{
    std::vector<int> v;

    v.push_back(start_a);
    v.push_back(start_b);

    while (true) {
        auto next = fn(v.back(), v.at(v.size() - 2));
        if (next > n) {
            break;
        }
        v.push_back(next);
    }

    return v;
}


/**
 * Generate the Fibonacci sequence up to a given value.
 *
 * @param n the maximum value (inclusive)
 * @returns a vector
 */
std::vector<int> fibonacciUpTo(int n)
{
    return recurrenceUpTo(n, std::plus<int>(), 1, 2);
}
