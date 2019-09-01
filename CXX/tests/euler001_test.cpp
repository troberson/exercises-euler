/*
 * Project Euler - 001 - Multiples of 3 and 5
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * NOTE:
 * Exclusive: Don't count 1000
 * Only count multiples of 3 or 5 once.
 */

#include <euler/euler001.hpp>

#include <catch2/catch.hpp>


namespace euler
{

TEST_CASE( "Euler 001: Example is correct" ) {
    REQUIRE( euler001_example() == 23 );
}

TEST_CASE( "Euler 001: Final answer is correct" ) {
    REQUIRE( euler001() == 233168 );
}

} // end namespace euler
