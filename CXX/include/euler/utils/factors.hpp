/*
 * Project Euler - Utils - factors
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for finding factors.
 */

#pragma once

#include "primes.hpp"
#include "template_types.hpp"

#include <algorithm> // std::sort, std::transform
#include <functional> // std::negate
#include <vector> // std::vector


/**
 * Find the factors of a number
 *
 * @note `includeNegative` is always true if `n` is negative
 *
 * @param n the number to factor
 * @param prime only look for prime factors (default: false)
 * @param includeNegative include negative numbers (default: false)
 * @returns the factors
 */
template <typename T, typename = IsIntegral<T>>
std::vector<T> factor(T n, bool prime = false, bool includeNegative = false)
{
    // There are no prime factors of a negative number, 0, or 1
    if (prime && n <= 1)
    {
        return {};
    }

    // Technically, zero has infinite factors but in lieu of that,
    // we just return { 0 }.
    if (n == 0)
    {
        return { 0 };
    }

    // If we are factoring a negative number, we must include negative
    // factors. This overrides the parameter.
    if (n < 0)
    {
        includeNegative = true;
        n = -n; // for all other purposes, n and -n are the same
    }

    // Find all positive factors.
    std::vector<T> facts;


    // Calculate the factors.
    //
    // Every time we find a factor, we record it and its complement
    // For prime factors, we are looking for only for the first
    // prime numbers whose product is the original number, so we divide
    // the number by the factor each time until we reach 1

    // The maximum number considered is calculated differently for
    // prime factors and regular factors.
    T max = n;
    for (T i = 1; i <= max; i++)
    {
        // Not a factor, continue
        if (n % i != 0)
        {
            continue;
        }

        // Prime factor check
        if (prime)
        {
            // Factor isn't prime, continue
            if (!is_prime(i))
            {
                continue;
            }

            // Add the factor to the list
            facts.push_back(i);

            // Only consider the numbers needed to
            // complete the product
            max /= i;
        }
        else // Regular factor check
        {
            // Add the factor to the list
            facts.push_back(i);

            // Also add its complement
            facts.push_back(n/i);

            // Only consider numbers towards the center (n/2)
            // Subtract 1 so we don't count the same factor twice
            max = n/i - 1;
        }
    }

    // Sort the list of factors
    // The regular factor check records numbers out of order
    std::sort(facts.begin(), facts.end());

    // The negative factors are the same as the positive factors,
    // so we just mirror the positive ones in a combined list
    if (includeNegative)
    {
        // Negate all factors into a new list
        std::vector<T> factsNeg;
        std::transform(facts.rbegin(), facts.rend(),
            std::back_inserter(factsNeg), std::negate<T>());

        // Return the two lists joined together
        std::vector<T> factsPosNeg(factsNeg);
        factsPosNeg.insert(factsPosNeg.end(), facts.begin(), facts.end());
        return factsPosNeg;
    }

    // Return factors
    return facts;
}
