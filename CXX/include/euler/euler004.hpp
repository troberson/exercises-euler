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

bool isPalindrome(int num);
int findLargestPalindromeProduct(int start, int end);

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
