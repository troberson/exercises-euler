/*
 * Project Euler - Utils - recurrence
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for recurrence relations, such as Fibonacci numbers.
 */

#pragma once

#include <vector>
#include <functional>

std::vector<int> recurrenceUpTo(
    int n, std::function<int(int)> fn, int start_a);

std::vector<int> recurrenceUpTo(
    int n, std::function<int(int, int)> fn, int start_a, int start_b);

std::vector<int> fibonacciUpTo(int n);
