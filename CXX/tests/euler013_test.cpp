/* Project Euler - 013 - Large sum
 * Copyright (c) 2019 Tamara Roberson
 *
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 *
 * (Defined in euler013.cpp)
 */

#include <euler/euler013.hpp>

#include <string> // std::string, std::substr

#include <catch2/catch.hpp>


namespace euler
{

// euler013()
// Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
TEST_CASE("Euler 013: Final answer is correct")
{
    REQUIRE(euler013() == "5537376230");
}


} // end namespace euler
