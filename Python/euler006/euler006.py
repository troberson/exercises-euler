#!/usr/bin/env python3

"""
Project Euler - 006 - Sum Square Difference

The sum of the squares of the first ten natural numbers is,
  1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
  (1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural
numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred
natural numbers and the square of the sum.
"""

from typing import Iterable as _Iterable


def main() -> int:
    """Return the result for the Project Euler problem."""
    return sum_square_difference(range(101))


def sum_square_difference(nums: _Iterable[int]) -> int:
    """Return the difference between the square of sums and the
    sum of squares of a list of numbers."""
    return square_of_sum(nums) - sum_of_squares(nums)


def square_of_sum(nums: _Iterable[int]) -> int:
    """Return the square of the sum of a list of numbers."""
    return sum(nums)**2


def sum_of_squares(nums: _Iterable[int]) -> int:
    """Return the sum of the square values of a list of numbers."""
    return sum((num**2 for num in nums))


if __name__ == "__main__":
    print(main())
