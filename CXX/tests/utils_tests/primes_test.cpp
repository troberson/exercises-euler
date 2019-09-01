/*
 * Project Euler - Utils - primes (Tests)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for finding prime numbers.
 */

#include <euler/utils/primes.hpp>

#include <catch2/catch.hpp>


namespace euler
{

// is_prime(n)
TEST_CASE("42 is not prime")
{
    REQUIRE(!utils::is_prime(42));
}

TEST_CASE("13 is prime")
{
    REQUIRE(utils::is_prime(13));
}

TEST_CASE("1 is not prime")
{
    REQUIRE(!utils::is_prime(1));
}

TEST_CASE("Long number prime check")
{
    REQUIRE(utils::is_prime(79L));
}

// find_next_prime(start)
TEST_CASE("First prime nuber is 2")
{
    REQUIRE(utils::find_next_prime(0) == 2);
}

TEST_CASE("The next prime number after 7 is 11")
{
    REQUIRE(utils::find_next_prime(7) == 11);
}

TEST_CASE("There are no prime numbers between 251 and 255 (uint8_t aka byte)")
{
    REQUIRE(utils::find_next_prime((uint8_t) 251) == (uint8_t) 0);
}

} // end namespace euler
