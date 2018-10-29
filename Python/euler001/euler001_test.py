#!/usr/bin/env python3


import euler001


def test_numbers_below_10_which_are_a_multiple_of_3_or_5():
    assert euler001.filter_multiples([3, 5], range(10))


def test_sum_numbers_below_10_which_are_a_multiple_of_3_or_5():
    assert euler001.sum_multiples([3, 5], range(10))


def test_final_sum_numbers_below_1000_which_are_a_multiple_of_3_or_5():
    assert euler001.main() == 233168
