/*
 * Project Euler - 008 - Largest product in a series
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * The four adjacent digits in the 1000-digit number that have the greatest
 * product are 9 × 9 × 8 × 9 = 5832.
 *
 * ...
 *
 * Find the thirteen adjacent digits in the 1000-digit number that have the
 * greatest product. What is the value of this product?
 */

#include <string> // std::string

namespace euler
{

/**
 * Solves the example problem.
 *
 * The four adjacent digits in the 1000-digit number that have the greatest
 * product are 9 × 9 × 8 × 9 = 5832.
 *
 * @returns the solution to the problem.
 */
int euler008_example();


/**
 * Solves the problem.
 *
 * Find the thirteen adjacent digits in the 1000-digit number that have the
 * greatest product. What is the value of this product?
 *
 * @returns the solution to the problem
 */
int64_t euler008();

} // end namespace euler
