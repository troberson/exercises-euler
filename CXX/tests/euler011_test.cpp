/* Project Euler - 011 - Largest product in a grid
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * In the 20×20 grid below, four numbers along a diagonal line have been
 * marked in red.
 *
 * (Grid defined in src/euler011.cpp.)
 *
 * The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20×20 grid?
 */

#include <euler/euler011.hpp>

#include <catch2/catch.hpp>

namespace euler
{

// euler011()
TEST_CASE("Euler 011: Final answer is correct")
{
    REQUIRE(euler011() == 70600674);
}

} // end namespace euler
