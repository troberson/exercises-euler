/*
 * Project Euler - Utils - maps
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for operating on maps.
 */

#include <euler/utils/maps.hpp>

#include <map> // std::map
#include <vector> // std::vector

#include <catch2/catch.hpp>


namespace euler::utils
{

TEST_CASE("Maps: get_map_keys()")
{
    SECTION("empty map")
    {
        std::map<int, int> input{};
        REQUIRE(get_map_keys(input).empty());
    }

    SECTION("characters")
    {
        std::map<char, int> input{
            {'a', 1},
            {'b', 2},
            {'c', 3},
        };

        std::vector<char> output{'a', 'b', 'c'};

        REQUIRE(get_map_keys(input) == output);
    }
}

TEST_CASE("Maps: get_map_values()")
{
    SECTION("empty map")
    {
        std::map<int, int> input{};
        REQUIRE(get_map_values(input).empty());
    }

    SECTION("characters")
    {
        std::map<char, int> input{
            {'a', 1},
            {'b', 2},
            {'c', 3},
        };

        std::vector<int> output{1, 2, 3};

        REQUIRE(get_map_values(input) == output);
    }
}




} // end namespace euler::utils
