/*
 * Project Euler - Utils - factors (Tests)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for finding factors.
 */

#include <euler/utils/factors.hpp>

#include <vector>

#include <catch2/catch.hpp>


namespace euler
{

// factor(n)
TEST_CASE("Factors of 24")
{
    std::vector<int> facts = { 1, 2, 3, 4, 6, 8, 12, 24 };
    REQUIRE(utils::factor(24) == facts);
}

TEST_CASE("Factors of -8")
{
    std::vector<int> facts = { -8, -4, -2, -1, 1, 2, 4, 8 };
    REQUIRE(utils::factor(-8) == facts);
}

TEST_CASE("Factors of 0")
{
    REQUIRE(utils::factor(0) == std::vector<int> { 0 });
}

TEST_CASE("Factors of 10, including negatives")
{
    std::vector<int> facts = { -10, -5, -2, -1, 1, 2, 5, 10 };
    REQUIRE(utils::factor(10, false, true) == facts);
}

TEST_CASE("Prime factors of 21")
{
    std::vector<int> facts = { 3, 7 };
    REQUIRE(utils::find_prime_factors(21) == facts);
}

TEST_CASE("Prime factors of -1")
{
    REQUIRE(utils::find_prime_factors(-1).empty());
}

// example of multiples of prime factors
TEST_CASE("Prime factors of 72")
{
    std::vector<int> results{2, 2, 2, 3, 3};
    REQUIRE(utils::find_prime_factors(72) == results);
}


TEST_CASE("Prime Factors of 600851475143")
{
    int64_t n = 600851475143;
    std::vector<int64_t> facts = { 71, 839, 1471, 6857 };
    REQUIRE(utils::find_prime_factors(n) == facts);
}


TEST_CASE("Factors: count_factors()")
{
    SECTION("There are 0 factors of 0")
    {
        REQUIRE(utils::count_factors(0) == 0);
    }

    SECTION("There are 2 factors of 13 (1 and 13)")
    {
        REQUIRE(utils::count_factors(13) == 2);
    }

    SECTION("There are 8 factors of 42 (1, 2, 3, 6, 7, 14, 21, 42)")
    {
        REQUIRE(utils::count_factors(42) == 8);
    }
}

} // end namespace euler
