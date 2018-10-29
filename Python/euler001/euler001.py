#!/usr/bin/env python3

"""
Project Euler - 001 - Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or 5, we
get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
"""

# NOTE:
# Exclusive: Don't count 1000
# Only count multiples of 3 or 5 once.

from typing import Iterable


__all__ = ["main", "sum_multiples", "filter_multiples"]


def main() -> int:
    """Return the result for the Project Euler problem."""
    return sum_multiples([3, 5], range(1000))


def sum_multiples(mult: Iterable[int], xs: Iterable[int]) -> int:
    """Return the sum of all numbers within 'xs' which are multiples of any numbers
    in 'mult'."""
    return sum(filter_multiples(mult, xs))


def filter_multiples(mult: Iterable[int], xs: Iterable[int]) -> Iterable[int]:
    """Return the list of numbers within 'xs' which are multiples of any numbers
    in 'mult'."""
    return [x for x in xs if x_is_multiple_of_any(x, mult)]


def x_is_multiple_of_any(x: int, ys: Iterable[int]) -> bool:
    return any([x_is_multiple_of_y(x, y) for y in ys])


def x_is_multiple_of_y(x: int, y: int) -> bool:
    return x % y == 0


if __name__ == '__main__':
    print(main())
