/*
 * Project Euler - 005 - Smallest Multiple
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 */

#include <euler/euler005.hpp>

#include <catch2/catch.hpp>


namespace euler
{

// euler005_example()
TEST_CASE("Euler 005: Example is correct")
{
    REQUIRE(euler005_example() == 2520);
}

// euler005()
TEST_CASE("Euler 005: Final answer is correct")
{
    REQUIRE(euler005() == 232792560);
}

} // end namespace euler
