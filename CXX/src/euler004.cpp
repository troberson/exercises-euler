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


namespace euler
{

bool is_palindrome(int num)
{
    return utils::is_palindrome(std::to_string(num));
}

int find_largest_palindrome_product(int start, int end)
{
    int largest = 0;

    for (int i = start; i <= end; i++)
    {
        for (int j = start; j <= end; j++)
        {
            int product = i * j;
            if (is_palindrome(product) && product > largest)
            {
                largest = product;
            }
        }
    }

    return largest;
}


int euler004_example()
{
    return find_largest_palindrome_product(10, 99);
}


int euler004()
{
    return find_largest_palindrome_product(100, 999);
}

} // end namespace euler
