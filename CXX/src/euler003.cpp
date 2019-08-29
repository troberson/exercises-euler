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

using namespace std;


/**
 * Solves the example problem.
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * @returns the solution to the problem.
 */
vector<int> euler003_example()
{
   return factor(13195, true);
}


/**
 * Solves the problem.
 *
 * What is the largest prime factor of the number 600851475143?
*
 * @returns the solution to the problem
 */
int euler003()
{
    auto facts = factor(600851475143, true);
    return facts.back();
}