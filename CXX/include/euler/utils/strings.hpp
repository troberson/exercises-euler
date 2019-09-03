/*
 * Project Euler - Utils - string
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for string operations
 */

#pragma once

#include <string> // std::string
#include <vector> // std:::vector


namespace euler::utils
{

/**
 * Check whether a string is a palindrome.
 *
 * A palindrome is a string of characters that reads the same
 * forwards as backwards.
 *
 * @note The current implementation requires no extra characters, such as
 *  spaces or punctuation.
 *
 * @param str the string to check
 * @returns true if string is a palindrome, false otherwise
 */
bool is_palindrome(std::string str);


/**
 * Convert a character to an integer
 *
 * @note This is a replacement for the traditional C-style
 *   std::atoi() which will throw an std::invalid_argument
 *   exception on invalid input, rather than returning 0.
 *
 * @param c a digit character
 * @returns an integer
 */
int char_to_int(char c);


/**
 * Convert a string of digits to a list of numbers
 *
 * @param str a string of digits
 * @returns a list of numbers
 */
std::vector<int> string_to_num_list(std::string str);

/**
 * Number grid
 *
 * A vector of vectors containing integers.
 * Rows are not guaranteed to all be the same length.
 */
using number_grid = std::vector<std::vector<int>>;

/**
 * Read number grid
 *
 * Convert a grid of numbers into a two-dimensional vector.
 * The format should be a long list of integers separated
 * by spaces. The `cols` parameter specifies how many columns
 * each of the rows should be. The last row may be short.
 *
 * @param grid_str a string representation of the grid
 * @param row_length the length of each row
 * @returns a vector of vectors representing the grid
 */
 number_grid read_number_grid(const std::string& grid_str, int col);

} // end namespace euler::utils
