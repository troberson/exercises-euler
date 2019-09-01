/*
 * Project Euler - 005 - Smallest Multiple
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 */

#include <euler/utils/maths.hpp>


namespace euler
{

int euler005_example()
{
    return utils::lcmRange(1, 10);
}


int euler005()
{
    return utils::lcmRange(1, 20);
}

} // end namespace euler
