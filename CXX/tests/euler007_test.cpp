/*
 * Project Euler - 007 - 10001st prime
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include <euler/euler007.hpp>

#include <catch2/catch.hpp>

namespace euler
{

/*
 * euler007_example()
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 */
TEST_CASE("Euler 007: Example is correct")
{
    REQUIRE(euler007_example() == 13);
}


/*
 * euler007()
 *
 * What is the 10 001st prime number?
 */

TEST_CASE("euler 007: Final answer is correct")
{
    REQUIRE(euler007() == 104743);
}

} // end namespace euler
