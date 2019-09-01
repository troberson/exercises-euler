/*
 * Project Euler - 003 - Largest Prime Factor
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 */

#include <euler/utils/factors.hpp>

#include <vector>


namespace euler
{

std::vector<int> euler003_example()
{
   return utils::factor(13195, true);
}


int euler003()
{
    auto facts = utils::factor(600851475143, true);
    return facts.back();
}

} // end namespace euler
