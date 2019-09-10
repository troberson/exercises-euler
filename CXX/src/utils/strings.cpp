/*
 * Project Euler - Utils - strings
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for string operations.
 */

#include <euler/utils/strings.hpp>

#include <algorithm> // std::clamp, std::transform
#include <sstream> // std::istringstream
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


number_grid read_number_grid(const std::string& grid_str, int cols)
{
    std::vector<std::vector<int>> grid;
    std::istringstream grid_stream(grid_str);
    std::string num_str;

    for (int n = 0; grid_stream >> num_str; n++)
    {
        std::vector<int> row;

        // Start new row
        if (n % cols == 0)
        {
            grid.push_back(row);
        }

        // Convert the word to a number
        int num = std::stoi(num_str);

        // Add it to the row
        grid.back().push_back(num);
    }

    return grid;
}


std::pair<std::string, std::string> split_string(const std::string& str, int pos)
{
    // If position is negative, count from the end
    if (pos < 0)
    {
        pos = str.length() + pos;
    }

    // Ensure that position is valid
    pos = std::clamp(pos, 0, static_cast<int>(str.length()));

    // Split the string
    auto part_a = str.substr(0, pos);
    auto part_b = str.substr(pos, str.length());

    // Return the pair of strings
    return {part_a, part_b};
}

} // end namespace euler::utils
