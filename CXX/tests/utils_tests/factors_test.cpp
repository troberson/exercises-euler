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
    REQUIRE(utils::factor(21, true) == facts);
}

TEST_CASE("Prime factors of -1")
{
    REQUIRE(utils::factor(-1, true).empty());
}

TEST_CASE("Prime Factors of 600851475143")
{
    auto n = 600851475143;
    std::vector<decltype(n)> facts = {
        71, 839, 1471, 6857 };
    REQUIRE(utils::factor(n, true) == facts);
}

} // end namespace euler
