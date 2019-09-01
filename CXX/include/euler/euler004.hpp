/*
 * Project Euler - 004 - Largest Palindrome Product
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#pragma once


namespace euler
{

/**
 * Check whether a number is a palindrome.
 *
 * A palindrome is a string that reads the same forwards and backwards.
 * This function converts an integer to a string and checks it.
 *
 * @param num the number to check
 * @returns true if number is a palindrome, false otherwise
 */
bool is_palindrome(int num);


/**
 * Find the largest product of a range of numbers which is a palindrome.
 *
 * For a given range of integers (inclusive), multiplies all combinations
 * together in pairs and returns the largest product which is a palindrome.
 *
 * @param start the number to start at (inclusive)
 * @param end the number to end at (inclusive)
 * @returns the largest product which is a palindrome.
 */
int find_largest_palindrome_product(int start, int end);

/**
 * Solves the example problem.
 *
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * @returns the solution to the problem.
 */
int euler004_example();


/**
 * Solves the problem.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * @returns the solution to the problem
 */
int euler004();

} // end namespace euler
