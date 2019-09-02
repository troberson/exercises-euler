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


namespace euler
{

// gcd(a, b)
TEST_CASE("Great common divisor of 10 and 15 is 5")
{
    REQUIRE(utils::gcd(10, 15) == 5);
}

TEST_CASE("Greatest common divisor of 0 and 1 is 1")
{
    REQUIRE(utils::gcd(0, 1) == 1);
}

TEST_CASE("Greatest common divisor of 2 and 0 is 2")
{
    REQUIRE(utils::gcd(2, 0) == 2);
}

TEST_CASE("Greatest common divisor of -2 and -3 is 6")
{
    REQUIRE(utils::gcd(-2, -3) == 1);
}


// lcm(a, b)
TEST_CASE("Least common multiple of 4 and 6 is 12")
{
    REQUIRE(utils::lcm(4, 6) == 12);
}

TEST_CASE("Least common multiple of 0 and 0 is 0")
{
    REQUIRE(utils::lcm(0, 0) == 0);
}

TEST_CASE("Least common multiple of -2 and -3 is 6")
{
    REQUIRE(utils::lcm(-2, -3) == 6);
}


// lcmList(nums)
TEST_CASE("Least common multiple of 1, 2, 3, 4, and 5 is 60")
{
    std::vector<int> nums = { 1, 2, 3, 4, 5 };
    REQUIRE(utils::lcmList(nums) == 60);
}


// lcmRange(start, end)
TEST_CASE("Least common multiple of 10 to 15 is 60060")
{
    REQUIRE(utils::lcmRange(10, 15) == 60060);
}


// product(vect)
TEST_CASE("The product of the numbers 1 to 5 is 120")
{
    auto nums = std::vector<int> { 1, 2, 3, 4, 5 };
    REQUIRE(utils::product<int>(nums) == 120);
}

} // end namespace euler
