/*
 * Project Euler - Utils - sum
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions to sum numbers in specialized ways.
 */


#include <euler/utils/strings.hpp>
#include <euler/utils/sum.hpp>

#include <algorithm> // std::any_of
#include <cmath> // std::log10
#include <functional> // std::plus
#include <limits> // std::numeric_limits
#include <stdexcept> // std::invalid_argument
#include <string> // std::string
#include <vector> // std::vector

namespace euler::utils
{

std::string sum_big_ints(std::vector<std::string> nums)
{
    // An empty vector returns a sum of 0
    if (nums.empty())
    {
        return "0";
    }

    // Integers must be all the same length
    int len_num = nums.at(0).length();
    if (std::any_of(nums.begin(), nums.end(),
        [=](auto n) { return n.length() != len_num; }))
    {
        throw std::invalid_argument("All integers must be the same length");
    }

    // Total
    std::string total_str{};

    // Calculate the piece size based on the maximum possible sum for
    // the size of the list of numbers.
    int piece_size = static_cast<int>(
        std::log10(std::numeric_limits<int64_t>::max() / nums.size()));

    // The amount to carry over to the next piece
    int64_t carry{0};

    // Walk through all the pieces
    int num_pieces = len_num / piece_size;
    for (int piece_num = 0; piece_num <= num_pieces; piece_num++)
    {
        // Starting position for the piece
        //   Ensure position is nonnegative
        int piece_idx_start = std::max(0, len_num - (piece_num + 1) * piece_size);

        // The last piece may be short
        if (piece_num == num_pieces)
        {
            piece_size = len_num % piece_size;
        }

        // Transform all the corresponding pieces into numbers and sum them
        int64_t sum = std::transform_reduce(
            nums.begin(), nums.end(), 0ULL,
            std::plus<>(),
            [=](auto s) {
                return std::stoull(s.substr(piece_idx_start, piece_size));
            });

        // Add the carry
        sum += carry;

        // Determine which digits to carry and which to add to the sum
        auto sum_str = std::to_string(sum);
        auto split_pos = sum_str.length() - piece_size;
        auto [carry_str, remainder_str] = utils::split_string(sum_str, split_pos);
        carry = std::stoull(carry_str);

        // Add the remainder to the sum
        total_str.insert(0, remainder_str);
   }

    // Add the final carry
    total_str.insert(0, std::to_string(carry));

    return total_str;
}

} // end namespace euler::utils
