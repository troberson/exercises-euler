#!/usr/bin/env python3

"""
Project Euler - 005 - Smallest Multiple

2520 is the smallest number that can be divided by each of the numbers from
1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the
numbers from 1 to 20?
"""

from functools import reduce as _reduce
from math import gcd as _gcd
from typing import Iterable as _Iterable


def main() -> int:
    """Return the result for the Project Euler problem."""
    return lcm_list(range(1, 21))


def lcm_list(xs: _Iterable[int]) -> int:
    """Return the least common multiple for all of a given list
    (or any iterable) of numbers."""
    return _reduce(lcm, xs)


def lcm(x: int, y: int) -> int:
    """Return the least common mulitple of two numbers."""
    return (x * y) // _gcd(x, y)


if __name__ == "__main__":
    print(main())
