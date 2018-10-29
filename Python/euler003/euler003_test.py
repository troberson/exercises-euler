#!/usr/bin/env python3

import euler003


def test_prime_factors_of_13195():
    assert euler003.prime_factors(13195) == [5, 7, 13, 29]


def test_final_largest_prime_factor_of_600851475143():
    assert euler003.main() == 6857
