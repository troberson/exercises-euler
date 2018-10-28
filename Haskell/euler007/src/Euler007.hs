-- Project Euler - 007 - 10001st prime
--
-- By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
-- that the 6th prime is 13.
--
-- What is the 10 001st prime number?

module Euler007 (euler007, primeNth, primesFirstN, primesToN) where

import Data.List.Ordered (minus)
import Data.Maybe (fromJust)

-- slower but unbounded (almost the same for our purposes ~0.01s)
-- import Numeric.Natural
-- type Nat = Natural

type Nat = Word

euler007 :: Nat
euler007 = primeNth 10001

primeNth :: Nat -> Nat
primeNth = last . primesFirstN

primesFirstN :: Nat -> [Nat]
primesFirstN n_nat = take n_int $ primesToN $ primeUpperBound n_nat
  where
    n_int = fromIntegral n_nat :: Int

getNth :: Nat -> [a] -> Maybe a
getNth n [] = Nothing
getNth n xs = Just $ xs !! fromIntegral (n-1)

primeUpperBound :: Nat -> Nat
primeUpperBound n_nat
  | n_nat < 3 = 3
  | otherwise = ceiling $ n * (log n + log (log n))
  where
    n = fromIntegral n_nat :: Float

primesToN :: Nat -> [Nat]
primesToN n = doRecursive sieve [2..n]
  where
    sieve x xs = xs `minus` [x*x, x*x+x..n]

-- |doRecursive: Apply a function which operates on a list recursively to the
-- |tail of a list, keeping the head each time.
doRecursive :: (a -> [a] -> [a]) -> [a] -> [a]
doRecursive f []     = []
doRecursive f (x:xs) = x : doRecursive f (f x xs)
