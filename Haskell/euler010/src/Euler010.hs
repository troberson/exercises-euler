-- Project Euler - 010 - Summation of primes
--
-- The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
-- Find the sum of all the primes below two million.
--
-- NOTE:
-- Prime function from Euler 007
module Euler010 (euler010, sumPrimesToN, primesToN) where

import Data.List.Ordered (minus)

-- Unbounded natural numbers are about 0.1s slower for the 2,000,000th prime
-- import Numeric.Natural
-- type Nat = Natural

type Nat = Word

euler010 :: Nat
euler010 = sumPrimesToN 2000000

sumPrimesToN :: Nat -> Nat
sumPrimesToN = sum . primesToN

primesToN :: Nat -> [Nat]
primesToN n = doRecursive sieve [2..n]
  where
    sieve x xs = xs `minus` [x*x, x*x+x..n]

-- |doRecursive: Apply a function which operates on a list recursively to the
-- |tail of a list, keeping the head each time.
doRecursive :: (a -> [a] -> [a]) -> [a] -> [a]
doRecursive f []     = []
doRecursive f (x:xs) = x : doRecursive f (f x xs)
