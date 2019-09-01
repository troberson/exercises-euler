/*
 * Project Euler - 007 - 10001st prime
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include <euler/euler007.hpp>
#include <euler/utils/primes.hpp>

namespace euler
{

int euler007_example()
{
    return utils::find_nth_prime<int>(6);
}



int euler007()
{
    return utils::find_nth_prime<int>(10001);
}

} // end namespace euler
