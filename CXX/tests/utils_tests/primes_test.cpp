/*
 * Project Euler - Utils - primes (Tests)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for finding prime numbers.
 */

#include <euler/utils/primes.hpp>

#include <catch2/catch.hpp>

// isPrime(n)
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

TEST_CASE("Long number prime check")
{
    REQUIRE(isPrime(79L));
}

// findNextPrime(start)
TEST_CASE("First prime nuber is 2")
{
    REQUIRE(findNextPrime(0) == 2);
}

TEST_CASE("The next prime number after 7 is 11")
{
    REQUIRE(findNextPrime(7) == 11);
}

TEST_CASE("There are no prime numbers between 251 and 255 (uint8_t aka byte)")
{
    REQUIRE(findNextPrime((uint8_t) 251) == (uint8_t) 0);
}
