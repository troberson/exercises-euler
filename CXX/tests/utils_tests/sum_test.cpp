/*
 * Project Euler - Utils - sum
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Returns the sum of a series of integers which are muliples of a number
 */

#include <euler/utils/sum.hpp>

#include <catch2/catch.hpp>


namespace euler
{

/* Sum of even numbers below 10
 *
 * sum_mult(10, 2)
 *
 * This returns 20 because 2 + 4 + 6 + 8 = 20.
 *
 */
TEST_CASE( "Sum of even numbers below 10" ) {
    REQUIRE(utils::sum_mult(10, 2) == 20 );
}

/* Sum of numbers below 10 divisible by 2 or 3
 *
 * sum_mult(10, 2, 3)
 *
 * This returns 32 because:
 * 2 + 4 + 6 + 8 = 20
 * 3 + 6 + 9 = 18
 * 20 + 18 - 6 (factor of both 2 and 3) = 32
 */
TEST_CASE( "Sum of numbers below 10 divisible by 2 or 3" ) {
    REQUIRE(utils::sum_mult(10, 2, 3) == 32);
}


/* Sum of even numbers from -10 to 0
 *
 * sum_mult(-10, 2)
 *
 * This returns -20 because -2 - 4 - 6 - 8 = -20.
 */
TEST_CASE("Sum of even numbers above -10 up to 0")
{
    REQUIRE(utils::sum_mult(-10, 2) == -20);
}

/* Sum of numbers below 10 divisible by 2 or 3
 *
 * sum_mult(10, 2, 3)
 *
 * This returns 32 because:
 * 2 + 4 + 6 + 8 = 20
 * 3 + 6 + 9 = 18
 * 20 + 18 - 6 (factor of both 2 and 3) = 32
 */
TEST_CASE("Sum of numbers above -10 up to 0 divisible by 2 or 3")
{
    REQUIRE(utils::sum_mult(-10, 2, 3) == -32);
}
} // end namespace euler
