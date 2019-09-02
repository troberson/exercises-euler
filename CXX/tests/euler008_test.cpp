/*
 * Project Euler - 008 - Largest product in a series
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * The four adjacent digits in the 1000-digit number that have the greatest
 * product are 9 × 9 × 8 × 9 = 5832.
 *
 * ...
 *
 * Find the thirteen adjacent digits in the 1000-digit number that have the
 * greatest product. What is the value of this product?
 */

#include <euler/euler008.hpp>

#include <catch2/catch.hpp>

namespace euler
{

/*
 * euler008_example()
 *
 * The four adjacent digits in the 1000-digit number that have the greatest
 * product are 9 × 9 × 8 × 9 = 5832.
 */
TEST_CASE("Euler 008: Example is correct")
{
    REQUIRE(euler008_example() == 5832);
}


/*
 * euler008()
 *
 * Find the thirteen adjacent digits in the 1000-digit number that have the
 * greatest product. What is the value of this product?
 */
TEST_CASE("Euler 008: Final answer is correct")
{
    REQUIRE(euler008() == 23514624000);
}

} // end namespace euler
