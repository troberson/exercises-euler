/*
 * Project Euler - Utils - recurrence
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for recurrence relations, such as Fibonacci numbers.
 */

#include <euler/utils/recurrence.hpp>

#include <functional>
#include <numeric>
#include <vector>


namespace euler::utils
{


std::vector<int> recurrence_up_to(int n, const std::function<int(int)>& fn, int start_a)
{
    std::vector<int> v;

    v.push_back(start_a);

    while (true) {
        auto next = fn(v.back());
        if (next > n) {
            break;
        }
        v.push_back(next);
    }

    return v;
}


std::vector<int> recurrence_up_to(
    int n, const std::function<int(int, int)>& fn, int start_a, int start_b)
{
    std::vector<int> v;

    v.push_back(start_a);
    v.push_back(start_b);

    while (true) {
        auto next = fn(v.back(), v.at(v.size() - 2));
        if (next > n) {
            break;
        }
        v.push_back(next);
    }

    return v;
}


std::vector<int> fibonacci_up_to(int n)
{
    return recurrence_up_to(n, std::plus<>(), 1, 2);
}

} // end namespace euler::utils
