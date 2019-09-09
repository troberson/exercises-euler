/*
 * Project Euler - Utils - TriangleNumberGenerator
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Generate triangle numbers
 */

// utils::TriangleNumberGenerator
#include <euler/utils/TriangleNumberGenerator.hpp>

#include <array> // std::array

#include <catch2/catch.hpp>


namespace euler
{

TEST_CASE("The 7th triangle number is 28")
{
    utils::TriangleNumberGenerator<int> triangle_gen;
    REQUIRE(triangle_gen[7] == 28);
}

TEST_CASE("The first ten triangle numbers are correct")
{
    utils::TriangleNumberGenerator<int> triangle_gen;
    std::vector<int> numbers{1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
    REQUIRE(triangle_gen.get_first_n(10) == numbers);
}

} // end namespace euler
