/*
 * Project Euler - Utils - recurrence (Tests)
 * Tamara Roberson <tamara.roberson@gmail.com>
 * Copyright (c) 2019 Tamara Roberson
 *
 * Functions for recurrence relations, such as Fibonacci numbers.
 */

#include <euler/utils/recurrence.hpp>

#include <catch2/catch.hpp>

TEST_CASE("Fibonacci sequence up to 100")
{
    std::vector<int> fibs = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    REQUIRE(fibonacciUpTo(100) == fibs);
}

TEST_CASE("Double the previous number up to 10,000")
{
    auto twice = [](int x) { return 2 * x; };
    std::vector<int> seq = { 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192 };
    REQUIRE(recurrenceUpTo(10000, twice, 2) == seq);
}
