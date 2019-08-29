/*
 * Project Euler - Utils - strings (Tests)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for string operations.
 */

#include <euler/utils/strings.hpp>

#include <catch2/catch.hpp>

// isPalindrome(str)
TEST_CASE("A palidrome: kayak")
{
    REQUIRE(isPalindrome("kayak"));
}

TEST_CASE("Not a palindrome: canoe")
{
    REQUIRE(!isPalindrome("canoe"));
}

TEST_CASE("An empty string is not a palindrome")
{
    REQUIRE(!isPalindrome(""));
}
