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

using namespace std;

vector<int> recurrenceUpTo(int n, function<int(int)> fn, int start_a);
vector<int> recurrenceUpTo(int n, function<int(int, int)> fn, int start_a, int start_b);
vector<int> fibonacciUpTo(int n);
