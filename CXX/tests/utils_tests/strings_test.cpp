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


// split_string(str, pos)
TEST_CASE("Strings: split_string()")
{
    std::string empty{};
    std::string digits{"0123456789"};

    SECTION("empty string")
    {
        auto [ output1, output2 ] = utils::split_string(empty, 1);
        REQUIRE(output1.empty());
        REQUIRE(output2.empty());
    }

    SECTION("normal string")
    {
        auto [output1, output2] = utils::split_string(digits, 5);
        REQUIRE(output1 == "01234");
        REQUIRE(output2 == "56789");
    }

    SECTION("negative position")
    {
        auto [output1, output2] = utils::split_string(digits, -3);
        REQUIRE(output1 == "0123456");
        REQUIRE(output2 == "789");
    }

    SECTION("position past end")
    {
        auto [output1, output2] = utils::split_string(digits, 20);
        REQUIRE(output1 == digits);
        REQUIRE(output2.empty());
    }
}

} // end namespace euler
