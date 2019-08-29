/*
 * Project Euler - Utils - primes
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for finding prime numbers.
 */

#pragma once

#include "template_types.hpp"

template <typename T, typename = IsIntegral<T>>
bool isPrime(T n);

template <typename T, typename = IsIntegral<T>>
T findNextPrime(T start);

#include "primes.tpp"
