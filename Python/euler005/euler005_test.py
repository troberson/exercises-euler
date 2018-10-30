#!/usr/bin/env python3

import euler005


def test_smallest_number_divisible_by_1_to_10_is_2520():
    assert euler005.lcm_list(range(1, 11)) == 2520


def test_final_smallest_number_divisible_by_1_to_20_is_232792560():
    assert euler005.main() == 232792560
