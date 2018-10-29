#!/usr/bin/env python3
# flake8: noqa

import euler004


def test_9009_is_a_palindrome():
    assert euler004.is_palindrome(9009)


def test_1234_is_not_a_palindrome():
    assert not(euler004.is_palindrome(1234))


def test_largest_palindrome_made_from_the_product_of_two_2_digit_numbers_is_9009():
    assert euler004.largest_palindrome_product(range(10, 100)) == 9009


def test_final_largest_palindrome_made_from_the_product_of_two_3_digit_numbers_is_906609():
    assert euler004.main() == 906609
