#!/usr/bin/env python3

import euler002
from itertools import islice


def test_first_ten_terms_of_fibonacci():
    assert \
        list(islice(euler002.fibonacci(), 10)) \
        == [1, 2, 3, 5, 8, 13, 21, 34, 55, 89]


def test_final_sum_of_even_fibonacci_up_to_4000000():
    assert euler002.main() == 4613732
