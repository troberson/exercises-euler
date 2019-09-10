/*
 * Project Euler - Utils - lists
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for operating on list-like containers,
 * including arrays, lists, strings, and vectors.
 */

#pragma once

#include "template_types.hpp" // utils::IsList

#include <map> // std::map


namespace euler::utils
{

/**
 * Count the number of occurrences in a list
 *
 * @tparam Element_t the type of elements in the list
 * @tparam Iterator_t the type of the iterator (must be an input iterator)
 * @param begin the iterator pointing to the beginning of the list
 * @param end the iterator pointing to the end of the list
 * @returns a sorted map containing the elements and the number of occurrences
 */
template <typename Element_t, typename Iterator_t,
    typename = IsInputIterator<Iterator_t>>
std::map<Element_t, int>
    count_occurrences(const Iterator_t& begin, const Iterator_t& end)
{
    // Map of the frequency counts
    std::map<Element_t, int> freq{};

    // Walk through all items
    for (auto it = begin; it != end; ++it)
    {
        // Get the value the iterator is pointing to
        Element_t val = *it;

        // If the value exists in the frequency map,
        // increment the counter; otherwise, set the
        // count to 1
        try {
            freq.at(val)++;
        } catch (...) {
            freq[val] = 1;
        }
    }

    // Return the frequency map
    return freq;
}

} // end namespace euler::utils
