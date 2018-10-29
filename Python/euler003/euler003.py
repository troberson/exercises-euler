#!/usr/bin/env python3

"""
Project Euler - 003 - Largest Prime Factor

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
"""


__all__ = ["main", "prime_factors"]

from itertools import count as _count
from typing import Iterable as _Iterable
from typing import List as _List


def main() -> int:
    """Return the result for the Project Euler problem."""
    return _largest_prime_factor(600851475143)


def prime_factors(n: int) -> _List[int]:
    """Return a list of the prime factors of a number."""
    return list(_factor_using(n, _primes()))


def _largest_prime_factor(n: int) -> int:
    return prime_factors(n)[-1]


def _factor_using(n: int, xs: _Iterable[int]) -> _Iterable[int]:
    for x in xs:
        if n < x:
            break
        elif _is_div(n, x):
            yield x
            n = n // x
        else:
            continue


def _primes() -> _Iterable[int]:
    n: int = 2
    yield n

    for n in _count(3, 2):
        if all((_is_not_div(n, x) for x in range(2, n//2))):
            yield n
        else:
            continue


def _is_div(n: int, d: int) -> bool:
    return n % d == 0


def _is_not_div(n: int, d: int) -> bool:
    return not(_is_div(n, d))


if __name__ == "__main__":
    print(main())
