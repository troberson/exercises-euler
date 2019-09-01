/*
 * Project Euler - Utils - strings (Tests)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for string operations.
 */

#include <euler/utils/strings.hpp>

#include <catch2/catch.hpp>


namespace euler
{

// is_palindrome(str)
TEST_CASE("A palidrome: kayak")
{
    REQUIRE(utils::is_palindrome("kayak"));
}

TEST_CASE("Not a palindrome: canoe")
{
    REQUIRE(!utils::is_palindrome("canoe"));
}

TEST_CASE("An empty string is not a palindrome")
{
    REQUIRE(!utils::is_palindrome(""));
}

} // end namespace euler
