/*
 * Project Euler - Utils - maps
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for operating on maps.
 */

#pragma once

#include <algorithm> // std::transform
#include <map> // std::map
#include <vector> // std::vector

namespace euler::utils
{

/**
 * Get one side of a map
 *
 * @tparam Output_t the type of the elements in the output vector
 * @tparam Key_t the type of the keys in the input map
 * @tparam Value_t the type of the values in the input map
 * @param input a map
 * @param key_side get the key side (true) or the value side (false) (default: true)
 * @returns a vector containing the keys or values from the map
 */
template<typename Output_t, typename Key_t, typename Value_t>
std::vector<Output_t> get_map_side(std::map<Key_t, Value_t> input, bool key_side = true)
{
    std::vector<Output_t> result{};
    result.reserve(input.size());

    std::transform(input.begin(), input.end(), std::back_inserter(result),
        [=] (const auto& pair)
        {
            return key_side ? pair.first : pair.second;
        }
    );

    return result;
}


/**
 * Get map keys
 *
 * @tparam Key_t the type of the keys in the input map
 * @tparam Value_t the type of the values in the input map
 * @param input a map
 * @returns a vector containing the keys from the map
 */
template<typename Key_t, typename Value_t>
std::vector<Key_t> get_map_keys(std::map<Key_t, Value_t> input)
{
    return get_map_side<Key_t>(input, true);
}

/**
 * Get map values
 *
 * @tparam Key_t the type of the keys in the input map
 * @tparam Value_t the type of the values in the input map
 * @param input a map
 * @returns a vector containing the values from the map
 */

template<typename Key_t, typename Value_t>
std::vector<Value_t> get_map_values(std::map<Key_t, Value_t> input)
{
    return get_map_side<Value_t>(input, false);
}

} // end namespace euler::utils
