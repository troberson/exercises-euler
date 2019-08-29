/*
 * Project Euler - 003 - Largest Prime Factor (Test)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 */

#include <euler/euler003.hpp>

#include <vector>

#include <catch2/catch.hpp>


TEST_CASE("Euler 003: Example is correct")
{
    std::vector<int> facts = { 5, 7, 13, 29 };
    REQUIRE(euler003_example() == facts);
}


TEST_CASE("Euler 003: Final answer is correct")
{
    REQUIRE(euler003() == 6857);
}
