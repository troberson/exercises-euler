/*
 * Project Euler - Utils - template types
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Convenience templates for describing types
 */

#pragma once

#include <type_traits>

template <typename T>
using IsIntegral = std::enable_if_t<std::is_integral_v<T>>;
