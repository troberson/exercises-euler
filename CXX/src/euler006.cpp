/*
 * Project Euler - 006 - Sum Square Difference
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * The sum of the squares of the first ten natural numbers is,
 *   1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 *   (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */

#include <euler/euler006.hpp>
#include <euler/utils/sum.hpp>


namespace euler
{

int square_of_sums(int max)
{
    int sum = utils::sum(max);
    return sum * sum;
}


int sum_square_difference(int max)
{
    return square_of_sums(max) - utils::sum_of_squares(max);
}


int euler006_example1()
{
    return utils::sum_of_squares(10);
}


int euler006_example2()
{
    return square_of_sums(10);
}


int euler006_example3()
{
    return sum_square_difference(10);
}


int euler006()
{
    return sum_square_difference(100);
}

} // end namespace euler

