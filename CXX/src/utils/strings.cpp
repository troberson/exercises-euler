/*
 * Project Euler - Utils - strings
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for string operations.
 */

#include <euler/utils/strings.hpp>

#include <algorithm> // std::transform
#include <string> // std::string
#include <vector> // std::vector

namespace euler::utils
{

bool is_palindrome(std::string str)
{
    // an empty string is not a palindrome
    if (str.empty())
    {
        return false;
    }

    // Check each character and it's mirror opposite
    // for differences, up to the center character
    int len = str.length();
    for (int i = 0; i <= len/2; i++)
    {
        if (str.at(i) != str.at(len - i - 1))
        {
            return false;
        }
    }

    // No inconsistencies found, must be a palindrome
    return true;
}


int char_to_int(const char c)
{
    return std::stoi(std::string(1, c));
}


std::vector<int> string_to_num_list(std::string str)
{
    std::vector<int> nums;
    std::transform(str.begin(), str.end(),
        std::back_inserter(nums), char_to_int);

    return nums;
}

} // end namespace euler::utils
