/*
 * Project Euler - 010 - Summation of primes
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

#include <euler/euler010.hpp>

#include <catch2/catch.hpp>

namespace euler
{

// euler010_example()
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
TEST_CASE("Euler 010: Example is correct")
{
    REQUIRE(euler010_example() == 17);
}


// euler010()
// Find the sum of all the primes below two million.
TEST_CASE("Euler 010: Final answer is correct")
{
    REQUIRE(euler010() == 142913828922);
}

} // end namespace euler
