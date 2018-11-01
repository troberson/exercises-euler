#!/usr/bin/env python3

import euler006


def test_sum_of_squares_of_1_to_10_is_385():
    assert euler006.sum_of_squares(range(1, 11)) == 385


def test_square_of_sum_of_1_to_10_is_3025():
    assert euler006.square_of_sum(range(1, 11)) == 3025


def test_sum_square_difference_of_1_to_10_is_2640():
    assert euler006.sum_square_difference(range(1, 11)) == 2640


def test_final_sum_square_difference_of_1_to_100_is_25164150():
    assert euler006.main() == 25164150
