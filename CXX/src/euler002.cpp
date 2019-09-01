/*
 * Project Euler - 002 - Even Fibonacci Numbers
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Each new term in the Fibonacci sequence is generated by adding the previous
 * two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 *     1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms.
 */

/*
 * Brute Force:
 * We could simply generate a Fibonacci sequence, filter the even ones, and find
 * the sum of the list. A running total would save some space.
 *
 * Better:
 * Of the first 10 terms in the Fibonacci sequence, only 3 are even: 2, 8, 34. In fact,
 * there are 32 terms under 4,000,000 but only 11 are even. We can say that only about
 * 1/3 of the Fibonacci numbers are even. Clearly, if we can avoid generating the 2/3
 * of the sequence we don't need, we should. So we can consider even Fibonacci numbers
 * simply a different recursive sequence and ignore generating all the odd ones.
 *
 * Generating even Fibonacci numbers the long way, we find:
 *
 *     2, 8, 34, 144, 610, ...
 *
 *  34 = 4 *   8 +  2
 * 144 = 4 *  34 +  8
 * 610 = 4 * 144 + 34
 *
 * So we have discovered the recursive sequence:
 *
 *     evenFib(n) = 4 * evenFib(n - 1) + evenFib(n - 2)
 *
 * Instead of seeding the pattern with fib(0) = 1 and fib(1) = 2, we seed it with
 * evenFib(0) = 2 and evenFib(1) = 8.
 */

#include <euler/euler002.hpp>
#include <euler/utils/recurrence.hpp>

#include <functional>
#include <numeric>
#include <vector>


namespace euler
{

std::vector<int> euler002_example()
{
    return utils::fibonacci_up_to(100);
}


int euler002()
{
    auto genNext = [](int a, int b) { return 4 * a + b; };
    auto v = utils::recurrence_up_to(4000000, genNext, 2, 8);
    return std::accumulate(v.begin(), v.end(), 0);
}

} // end namespace euler
