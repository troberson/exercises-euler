/*
 * Project Euler - Utils - strings (Tests)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for string operations.
 */

#include <euler/utils/strings.hpp>

#include <string> // std::string
#include <vector> // std::vector

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


// char_to_int(c)
TEST_CASE("'1' converts to 1")
{
    REQUIRE(utils::char_to_int('1') == 1);
}


// string_to_num_list(str)
TEST_CASE("'12345' converts to {1, 2, 3, 4, 5}")
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    REQUIRE(utils::string_to_num_list("12345") == nums);
}

// read_number_grid(grid_str, row_length)
TEST_CASE("Number grid '1 2 3 4' converts to {{1, 2}, {3, 4}}")
{
    auto nums_str = std::string("1 2 3 4");
    std::vector<std::vector<int>> nums = {{1, 2}, {3, 4}};
    REQUIRE(utils::read_number_grid(nums_str, 2) == nums);
}

} // end namespace euler
