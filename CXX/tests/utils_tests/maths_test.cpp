/*
 * Project Euler - Utils - maths (Test)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Miscellaneous maths functions.
 */

#include <euler/utils/maths.hpp>

#include <vector> // std::vector

#include <catch2/catch.hpp>

// gcd(a, b)
TEST_CASE("Great common divisor of 10 and 15 is 5")
{
    REQUIRE(gcd(10, 15) == 5);
}

// lcm(a, b)
TEST_CASE("Least common multiple of 4 and 6 is 12")
{
    REQUIRE(lcm(4, 6) == 12);
}

// lcmList(nums)
TEST_CASE("Least common multiple of 1, 2, 3, 4, and 5 is 60")
{
    std::vector<int> nums = { 1, 2, 3, 4, 5 };
    REQUIRE(lcmList(nums) == 60);
}

// lcmRange(start, end)
TEST_CASE("Least common multiple of 10 to 15 is 60060")
{
    REQUIRE(lcmRange(10, 15) == 60060);
}
