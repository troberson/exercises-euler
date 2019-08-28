/*
 * Project Euler - Utils - primes
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for finding prime numbers.
 */

#pragma once

#include <type_traits>

template <typename T>
using IsIntegral = std::enable_if_t<std::is_integral_v<T>>;

template <typename T, typename = IsIntegral<T>>
bool isPrime(T n);

#include "primes.tpp"
