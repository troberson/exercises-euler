/*
 * Project Euler - Utils - primes
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for finding prime numbers.
 */

#pragma once

#include "template_types.hpp"

#include <limits> // std::numeric_limits
#include <vector> // std::vector


namespace euler::utils
{

/**
 * Check if a number is prime.
 *
 * Valid for any integral type (int, long, unsigned int, etc.).
 * Uses trial division.
 *
 * @param n number to check
 * @returns true if number is prime, false otherwise
 */
template <typename T, typename = IsIntegral<T>>
bool is_prime(T n)
{
    // Negative numbers, 0, and 1 are not prime
    if (n < 2)
    {
        return false;
    }

    // 2 is prime
    if (n == 2)
    {
        return true;
    }

    // All other even numbers are not prime
    if (n % 2 == 0)
    {
        return false;
    }

    // Test all odd numbers up to n/2
    for (int i = 3; i < n/2; i += 2)
    {
        // Found a divisor, number is not prime
        if (n % i == 0) {
            return false;
        }
    }

    // Did not find a divisor, number is prime
    return true;
}


/**
 * Find next prime
 *
 * @param start number to start from
 * @returns a prime number or 0 if max size of type is reached
 */
template <typename T, typename = IsIntegral<T>>
T find_next_prime(T start)
{
    // The first prime number is 2
    if (start < 2)
    {
        return 2;
    }

    // Start searching from the next number after the one
    // we are given
    start++;

    // Start on an odd number, so we can only test odd numbers
    if (start % 2 == 0)
    {
        start++;
    }

    // Search for the next prime number
    T max = std::numeric_limits<T>::max();
    for (int i = start; i <= max; i += 2)
    {
        if (is_prime(i))
        {
            return i;
        }
    }

    // return 0 if we hit the maximum of the type without reaching another prime number
    return 0;
}


/**
 * Find Nth prime number
 *
 * @param n the number of the prime to find
 * @returns the Nth prime
 */
template <typename T, typename = IsIntegral<T>>
T find_nth_prime(int n)
{
    T prime = 0;

    for (int i = 0; i < n; i++)
    {
        prime = find_next_prime(prime);
    }

    return prime;
}

/**
 * Find all prime numbers below a given number.
 *
 * @tparam T the output type
 * @tparam U the input type
 * @param max the highest value of the prime numbers to find
 * @returns a vector of prime numbers
 */
template <
    typename T, typename U,
    typename = IsIntegral<T>, typename = IsIntegral<U>>
std::vector<T> primes_up_to(U max)
{
    // If max is 0 or negative, return an empty vector.
    if (max <= 0) {
        return {};
    }

    std::vector<T> primes;
    std::vector<bool> sieve(max);

    // The first prime number is 2
    // we can only address odd numbers
    primes.push_back(2);

    // Walk through the sieve
    for (T i = 3; i < max; i += 2) {

        // Skip if already crossed off as composite
        if (sieve.at(i))
        {
            continue;
        }

        // Number is prime, add to list
        primes.push_back(i);

        // If the square of the number is greater than the maximum,
        // we don't need to look for multiples
        if (i * i > max)
        {
            continue;
        }

        // Register all multiples of the prime as not prime
        for (T j = i * i; j < sieve.size(); j += i)
        {
            sieve.at(j) = true;
        }
    }

   return primes;
}

} // end namespace euler::utils
