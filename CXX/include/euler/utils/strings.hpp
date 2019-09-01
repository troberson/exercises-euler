/*
 * Project Euler - Utils - string
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for string operations
 */

#pragma once

#include <string>


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

} // end namespace euler::utils
