/*
 * Project Euler - Utils - maths (Test)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Miscellaneous maths functions.
 */

#include <euler/utils/maths.hpp>

#include <cmath> // std::sqrt
#include <limits> // std::numeric_limits
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


// generate_pythagorean_triplet(m, n)
TEST_CASE("Pythagorean triplets cannot be generated with negative numbers")
{
    REQUIRE_THROWS(utils::generate_pythagorean_triplet<int>(-1, -2));
}

TEST_CASE(
    "Pythagorean triplets cannot be generated with the first parameter " \
    "less than or equal to the second"
)
{
    REQUIRE_THROWS(utils::generate_pythagorean_triplet<int>(1, 2));
}

TEST_CASE(
    "Throw if the output type is not large enough to hold the result"
)
{
    // Find the max for int64_t
    auto max = std::numeric_limits<int64_t>::max();

    // The largest value of the formula is 2 * m * n,
    // so find the square root of half the max to find
    // the largest possible value of m for an int64_t.
    auto m = static_cast<int64_t>(std::ceil(std::sqrt(max / 2)));

    // m and m - 1 should be the largest values possible,
    // so m + 1 and m should be too large
    REQUIRE_THROWS(utils::generate_pythagorean_triplet<int64_t>(m + 1, m));
}

TEST_CASE(
    "Do not throw if the output type is large enough to hold the result"
)
{
    // Find the max for int64_t
    auto max = std::numeric_limits<int64_t>::max();

    // The largest value of the formula is 2 * m * n,
    // so find the square root of half the max to find
    // the largest possible value of m for an int64_t.
    auto m = static_cast<int64_t>(std::ceil(std::sqrt(max / 2)));

    // m and m - 1 should be the largest values possible
    REQUIRE_NOTHROW(utils::generate_pythagorean_triplet<int64_t>(m, m - 1));
}

TEST_CASE("The Pythagorean triplet generated with m = 2 and n = 1 is { 3, 4, 5 }")
{
    auto nums = std::vector<int> { 3, 4, 5 };
    REQUIRE(utils::generate_pythagorean_triplet<int>(2, 1) == nums);
}

} // end namespace euler
