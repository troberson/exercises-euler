/*
 * Project Euler - 001 - Multiples of 3 and 5
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * NOTE:
 * Exclusive: Don't count 1000
 * Only count multiples of 3 or 5 once.
 */

/*
 * Brute Force:
 * The brute-force method would be to list all the numbers under 1000 which
 * are multiples of 3, sum those, add those which are multiples of 5, and
 * subtract those which are multiples of 15.
 *
 * Better:
 * However, we can also use the method attributed to the child Gauss for
 * finding the sum of a series of natural numbers: n(n-1)/2. So, for example,
 * the sum of the numbers 1 to 100 are 100*101/2 = 5050.
 *
 * The set of numbers under 1000 divisible by 3 can be described as
 * { 3n | for 0 <= n < floor(999/2) } so therefore the sum of the numbers
 * under 1000 divisible by 3 is 3*333*334/2, for 5, it is
 * 5*199*20=0/5, and for 15, 15*66*67/2.
 */

#include <euler/utils/sumMult.hpp>


unsigned int euler001_example()
{
  return sumMult(10, 3, 5);
}


unsigned int euler001()
{
  return sumMult(1000, 3, 5);
}
