/*
 * Project Euler - 010 - Summation of primes
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

#include <euler/euler010.hpp>
#include <euler/utils/primes.hpp> // utils::primes_up_to
#include <euler/utils/sum.hpp> // utils::sum

#include <cstdint> // int64_t
#include <vector> // std::vector

namespace euler
{

int euler010_example()
{
    auto primes = utils::primes_up_to<int>(10);
    return utils::sum<int>(primes);
}

int64_t euler010()
{
    auto primes = utils::primes_up_to<int64_t>(2000000);
    return utils::sum<int64_t>(primes);
}

} // end namespace euler
