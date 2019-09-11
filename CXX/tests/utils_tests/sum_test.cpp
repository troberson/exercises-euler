/*
 * Project Euler - Utils - sum
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions to sum numbers in specialized ways.
 */

#include <euler/utils/sum.hpp>

#include <string> // std::string
#include <vector> // std::vector

#include <catch2/catch.hpp>


namespace euler
{

/* Sum of even natural numbers from 0 to 9
 *
 * sum_mult(9, 2)
 *
 * This returns 20 because 2 + 4 + 6 + 8 = 20.
 *
 */
TEST_CASE("Sum of even natural numbers from 0 to 9") {
    REQUIRE(utils::sum_mult(9, 2) == 20 );
}

/* Sum of natural numbers from 0 to 9 divisible by 2 or 3
 *
 * sum_mult(9, 2, 3)
 *
 * This returns 32 because:
 * 2 + 4 + 6 + 8 = 20
 * 3 + 6 + 9 = 18
 * 20 + 18 - 6 (factor of both 2 and 3) = 32
 */
TEST_CASE("Sum of natural numbers from 0 to 9 divisible by 2 or 3") {
    REQUIRE(utils::sum_mult(9, 2, 3) == 32);
}


/* Sum of negative even integers from -9 to 0
 *
 * sum_mult(-9, 2)
 *
 * This returns -20 because -2 - 4 - 6 - 8 = -20.
 */
TEST_CASE("Sum of negative even integers from -9 to 0")
{
    REQUIRE(utils::sum_mult(-9, 2) == -20);
}

/* Sum of negative integers from -9 to 0 which are divisible by 2 or 3
 *
 * sum_mult(-9, 2, 3)
 *
 * This returns 32 because:
 * 2 + 4 + 6 + 8 = 20
 * 3 + 6 + 9 = 18
 * 20 + 18 - 6 (factor of both 2 and 3) = 32
 */
TEST_CASE("Sum of negative integers from -9 to 0 which are divisible by 2 or 3")
{
    REQUIRE(utils::sum_mult(-9, 2, 3) == -32);
}


// sum_big_ints()
TEST_CASE("Sum: sum_big_ints()")
{
    std::vector<std::string> empty{};

    std::vector<std::string> digits{
        "1111111111",
        "2222222222",
        "3333333333",
        "4444444444",
        "5555555555",
        "6666666666",
        "7777777777",
        "8888888888",
        "9999999999"};

    SECTION("empty list")
    {
        REQUIRE(utils::sum_big_ints(empty) == "0");
    }

    SECTION("normal sum")
    {
        REQUIRE(utils::sum_big_ints(digits) == "49999999995");
    }

    SECTION("irregular length")
    {
        auto digits_bad = digits;
        digits_bad.emplace_back("123");
        REQUIRE_THROWS(utils::sum_big_ints(digits_bad));
    }
}

} // end namespace euler
