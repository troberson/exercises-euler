/*
 * Project Euler - Utils - lists
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for operating on list-like containers,
 * including arrays, lists, strings, and vectors.
 */

#include <euler/utils/lists.hpp>

#include <map> // std::map
#include <string> // std::string
#include <vector> // std::vector

#define CATCH_CONFIG_ENABLE_PAIR_STRINGMAKER
#include <catch2/catch.hpp>


namespace euler::utils
{

TEST_CASE("Lists: count_occurrences()", "[lists][count_occurrences]")
{

SECTION("vector")
{
    std::vector<int> input{5, 1, 1, 1, 2, 6, 2, 1, 3, 4, 4, 4, 5, 5};
    std::map<int, int> output{{1, 4}, {2, 2}, {3, 1}, {4, 3}, {5, 3}, {6, 1}};
    REQUIRE(count_occurrences<int>(input.begin(), input.end()) == output);
}


SECTION("string")
{
    std::string input{"this is a test"};
    std::map<char, int> output{
        {' ', 3}, {'a', 1}, {'e', 1}, {'h', 1}, {'i', 2}, {'s', 3}, {'t', 3}
    };
    REQUIRE(count_occurrences<char>(input.begin(), input.end()) == output);
}

} // end TEST_CASE

} // end namespace euler::utils
