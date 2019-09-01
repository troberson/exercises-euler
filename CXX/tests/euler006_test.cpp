/*
 * Project Euler - 006 - Sum Square Difference
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 */

#include <euler/euler006.hpp>

#include <catch2/catch.hpp>


namespace euler
{

/*
 * euler006_example1()
 *
 * The sum of the squares of the first ten natural numbers is,
 *   1^2 + 2^2 + ... + 10^2 = 385
 */
TEST_CASE("Euler 006: Example 1 is correct")
{
    REQUIRE(euler006_example1() == 385);
}


/*
 * euler006_example2()
 *
 * The square of the sum of the first ten natural numbers is,
 *   (1 + 2 + ... + 10)^2 = 55^2 = 3025
 */
TEST_CASE("Euler 006: Example 2 is correct")
{
    REQUIRE(euler006_example2() == 3025);
}


/*
 * euler006_example3()
 *
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 */
TEST_CASE("Euler 006: Example 3 is correct")
{
    REQUIRE(euler006_example3() == 2640);
}


/*
 * euler006()
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */
TEST_CASE("Euler 006: Final answer is correct")
{
    REQUIRE(euler006() == 25164150);
}

} // end namespace euler
