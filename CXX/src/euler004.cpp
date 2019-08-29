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

#include <euler/utils/strings.hpp>

#include <string> // std::to_string

bool isPalindrome(int num)
{
    return isPalindrome(std::to_string(num));
}

int findLargestPalindromeProduct(int start, int end)
{
    int largest = 0;

    for (int i = start; i <= end; i++)
    {
        for (int j = start; j <= end; j++)
        {
            int product = i * j;
            if (isPalindrome(product) && product > largest)
            {
                largest = product;
            }
        }
    }

    return largest;
}


/**
 * Solves the example problem.
 *
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * @returns the solution to the problem.
 */
int euler004_example()
{
    return findLargestPalindromeProduct(10, 99);
}


/**
 * Solves the problem.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * @returns the solution to the problem
 */
int euler004()
{
    return findLargestPalindromeProduct(100, 999);
}
