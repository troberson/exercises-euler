/*
 * Project Euler - 004 - Largest Palindrome Product
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 */

#include <euler/euler004.hpp>

#include <catch2/catch.hpp>

// isPalindrome(num)
TEST_CASE("Palindromic number: 1234321")
{
    REQUIRE(isPalindrome(1234321));
}

TEST_CASE("Not a palindromic number: 123456789")
{
    REQUIRE(!isPalindrome(123456789));
}

// findLargestPalindromeProduct(start, end)
TEST_CASE("Largest palindromic product from 10 to 19")
{
    REQUIRE(findLargestPalindromeProduct(10, 19) == 323);
}


// euler004_example()
TEST_CASE("Euler 004: Example is correct")
{
    REQUIRE(euler004_example() == 9009);
}

// euler004()
TEST_CASE("Euler 004: Final answer is correct")
{
    REQUIRE(euler004() == 906609);
}