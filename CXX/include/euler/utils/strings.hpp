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

} // end namespace euler::utils
