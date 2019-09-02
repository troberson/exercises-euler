/*
 * Project Euler - Utils - template types
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Convenience templates for describing types
 */

#pragma once

#include <type_traits>


namespace euler::utils
{

/**
 * Type alias to check if a template parameter is a number.
 *
 * The function this is applied to will only be enabled if given
 * a numeric parameter.
 *
 * @tparam T the type of the number
 */
template <typename T>
using IsArithmetic = std::enable_if_t<std::is_arithmetic_v<T>>;

/**
 * Type alias to check if a template parameter is an integral.
 *
 * The function this is applied to will only be enabled if given
 * an integral parameter.
 *
 * @tparam T the type of the number
 */
template <typename T>
using IsIntegral = std::enable_if_t<std::is_integral_v<T>>;

} // end namespace euler::utils
