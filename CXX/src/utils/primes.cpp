/*
 * Project Euler - Utils - primes
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for finding prime numbers.
 */

#include <euler/utils/primes.hpp>

/**
 * Check if a number is prime.
 *
 * Uses trial division.
 *
 * @param n number to check
 * @returns true if number is prime, false otherwise
 */
bool isPrime(int n)
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
