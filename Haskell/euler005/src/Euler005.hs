-- Project Euler - 005 - Smallest multiple
--
-- 2520 is the smallest number that can be divided by each of the numbers from
-- 1 to 10 without any remainder.
--
-- What is the smallest positive number that is evenly divisible by all of the
-- numbers from 1 to 20?
module Euler005 (euler005, lcmList) where

euler005 :: Integer
euler005 = lcmList [1..20]

lcmList :: [Integer] -> Integer
lcmList = foldl1 lcm
