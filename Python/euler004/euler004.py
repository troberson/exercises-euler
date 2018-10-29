#!/usr/bin/env python3

"""
Project Euler - 004 - Largest Palindrome Product

A palindromic number reads the same both ways. The largest palindrome made
from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
"""

__all__ = ["main", "largest_palindrome_product", "is_palindrome"]


from typing import Any as _Any
from typing import Iterable as _Iterable


def main() -> int:
    """Return the result for the Project Euler problem."""
    return largest_palindrome_product(range(100, 1000))


def largest_palindrome_product(xs: _Iterable[int]) -> int:
    """Return the largest numeric palindrome with the product of a combination
    of numbers in 'xs'."""
    return max(_palindromes(_products(xs)))


def is_palindrome(x: _Any) -> bool:
    """Returns True if a given object's text representation (str()) is a
    palindrome."""
    x_str = str(x)
    return x_str == x_str[::-1]


def _palindromes(xs: _Iterable[int]) -> _Iterable[int]:
    """Returns an iterable which is a filtered version of 'xs' containing only
    palindromes."""
    return filter(is_palindrome, xs)


def _products(xs: _Iterable[int]) -> _Iterable[int]:
    """Returns an iterator generating the products for every combination of
    'xs'."""
    return (x * y for x in xs for y in xs if x <= y)
