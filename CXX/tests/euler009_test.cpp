/*
 * Project Euler - 009 - Special Pythagorean triplet
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c,
 * for which,
 *
 *      a^2 + b^2 = c^2
 *
 * For example,
 *
 *      3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *
 * Find the product abc.
 */

#include <euler/euler009.hpp>

#include <vector> // std::vector

#include <catch2/catch.hpp>


namespace euler
{

// find_pythagorean_triplet_with_sum(sum)
TEST_CASE("A 3-4-5 Pythagorean triplet has a sum of 12")
{
    auto triplet = std::vector<int> { 3, 4, 5 };
    REQUIRE(find_pythagorean_triplet_with_sum(12) == triplet);
}

TEST_CASE("Find a Pythagorean triplet with a sum of 1000")
{
    auto triplet = std::vector<int> { 375, 200, 425 };
    REQUIRE(find_pythagorean_triplet_with_sum(1000) == triplet);
}


// euler009()
TEST_CASE("Euler 009: Final answer is correct")
{
    REQUIRE(euler009() == 31875000);
}

} // end namespace euler
