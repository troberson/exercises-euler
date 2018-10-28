-- Project Euler - 001 - Multiples of 3 and 5
--
-- If we list all the natural numbers below 10 that are multiples of 3 or 5, we
-- get 3, 5, 6 and 9. The sum of these multiples is 23.
--
-- Find the sum of all the multiples of 3 or 5 below 1000.
-- ---------- 
-- NOTE:
-- Exclusive: Don't count 1000
-- Only count multiples of 3 or 5 once.
module Euler001 (euler001, filterMultiples, sumMultiples) where

isMultipleOf :: Int -> Int -> Bool
isMultipleOf n d = n `rem` d == 0

isMultipleOfAny :: Int -> [Int] -> Bool
isMultipleOfAny = any . isMultipleOf

filterMultiples :: [Int] -> [Int] -> [Int]
filterMultiples mult = filter (`isMultipleOfAny` mult)

sumMultiples :: [Int] -> [Int] -> Int
sumMultiples mult = sum . filterMultiples mult

euler001 :: Int
euler001 = sumMultiples [3, 5] [1..999]
