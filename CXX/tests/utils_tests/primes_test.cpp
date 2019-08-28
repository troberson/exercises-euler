/*
 * Project Euler - Utils - primes (Tests)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for finding prime numbers.
 */

#include <euler/utils/primes.hpp>

#include <catch2/catch.hpp>

TEST_CASE("42 is not prime")
{
    REQUIRE(!isPrime(42));
}

TEST_CASE("13 is prime")
{
    REQUIRE(isPrime(13));
}

TEST_CASE("1 is not prime")
{
    REQUIRE(!isPrime(1));
}
