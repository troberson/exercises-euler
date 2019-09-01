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

/* Sum of even natural numbers from 0 to 9
 *
 * sum_mult(9, 2)
 *
 * This returns 20 because 2 + 4 + 6 + 8 = 20.
 *
 */
TEST_CASE("Sum of even natural numbers from 0 to 9") {
    REQUIRE(utils::sum_mult(9, 2) == 20 );
}

/* Sum of natural numbers from 0 to 9 divisible by 2 or 3
 *
 * sum_mult(9, 2, 3)
 *
 * This returns 32 because:
 * 2 + 4 + 6 + 8 = 20
 * 3 + 6 + 9 = 18
 * 20 + 18 - 6 (factor of both 2 and 3) = 32
 */
TEST_CASE("Sum of natural numbers from 0 to 9 divisible by 2 or 3") {
    REQUIRE(utils::sum_mult(9, 2, 3) == 32);
}


/* Sum of negative even integers from -9 to 0
 *
 * sum_mult(-9, 2)
 *
 * This returns -20 because -2 - 4 - 6 - 8 = -20.
 */
TEST_CASE("Sum of negative even integers from -9 to 0")
{
    REQUIRE(utils::sum_mult(-9, 2) == -20);
}

/* Sum of negative integers from -9 to 0 which are divisible by 2 or 3
 *
 * sum_mult(-9, 2, 3)
 *
 * This returns 32 because:
 * 2 + 4 + 6 + 8 = 20
 * 3 + 6 + 9 = 18
 * 20 + 18 - 6 (factor of both 2 and 3) = 32
 */
TEST_CASE("Sum of negative integers from -9 to 0 which are divisible by 2 or 3")
{
    REQUIRE(utils::sum_mult(-9, 2, 3) == -32);
}

} // end namespace euler
