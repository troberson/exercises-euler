/*
 * Project Euler - Utils - strings (Tests)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for string operations.
 */

#include <euler/utils/strings.hpp>

#include <catch2/catch.hpp>

// is_palindrome(str)
TEST_CASE("A palidrome: kayak")
{
    REQUIRE(is_palindrome("kayak"));
}

TEST_CASE("Not a palindrome: canoe")
{
    REQUIRE(!is_palindrome("canoe"));
}

TEST_CASE("An empty string is not a palindrome")
{
    REQUIRE(!is_palindrome(""));
}
