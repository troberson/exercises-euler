/*
 * Project Euler - 002 - Even Fibonacci Numbers (Test)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 */

#include <euler/euler002.hpp>

#include <catch2/catch.hpp>

TEST_CASE("Euler 002: Example is correct")
{
    vector<int> fibs = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    REQUIRE(euler002_example() == fibs);
}

TEST_CASE("Euler 002: Final answer is correct")
{
    REQUIRE(euler002() == 4613732);
}
