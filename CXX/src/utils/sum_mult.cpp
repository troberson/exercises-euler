/*
 * Project Euler - Utils - sum_mult
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Returns the sum of a series of integers which are muliples of a number
 */

/*
 * These methods use strategy attributed to the child Gauss for finding the
 * sum of a series of natural numbers: n(n-1)/2. So, for example, the sum of
 * the numbers 1 to 100 are 100*101/2 = 5050.
 *
 * To sum only multiples of a particular number, we divide the maximum number,
 * n, by the number we want to use multiples of, or 'step', (we only need the
 * integer floor) and we use this number, call it n', in place of n.
 * Multiplying the step by the new equation n'(n'-1)/2 gives us the sum.
 *
 * To sum only multiples of two different numbers, we find the sum as above for
 * each step individually, then find the sum using the product of the two sums.
 * Adding the two step sums and subtracting the product sum gives us the final
 * total. If we wanted to include additional steps, we would follow the
 * Principle of Inclusion-Exclusion and alternately subtract and add sums as
 * required.
 */

#include <euler/utils/sum_mult.hpp>

unsigned int sum_mult(unsigned int max, unsigned int step)
{
  int n = (max - 1) / step;
  return step * n * (n + 1) / 2;
}


unsigned int sum_mult(unsigned int max, unsigned int step_a, int step_b)
{
  return sum_mult(max, step_a) + sum_mult(max, step_b) - sum_mult(max, step_a * step_b);
}
