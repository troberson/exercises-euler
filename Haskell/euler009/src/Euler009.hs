-- Project Euler - 009 - Special Pythagorean triplet
--
-- A Pythagorean triplet is a set of three natural numbers, a < b < c,
-- for which,
--
--      a^2 + b^2 = c^2
--
-- For example,
--
--      3^2 + 4^2 = 9 + 16 = 25 = 5^2.
--
-- There exists exactly one Pythagorean triplet for which a + b + c = 1000.
--
-- Find the product abc.
-- ----------
--
-- NOTE:
-- A basic method for finding Pythagorean triplets is with the formula:
--
--      a = r^2 - s^2
--      b = 2rs
--      c = r^2 + s^2
--      r > s > 0 are whole numbers
--      r - s is odd
--
-- For primitive Pythagorean triplets:
--
--      the greatest common divisor of r and s is 1.
--
--  (http://mathforum.org/dr.math/faq/faq.pythag.triples.html)
module Euler009
  ( euler009
  , findTripletProductWithSumN
  , findTripletWithSumN
  ) where

import Data.Maybe (catMaybes, fromJust)

-- We know there exists a triplet with a sum of 1000,
-- so fromJust isn't a problem
euler009 :: Int
euler009 = fromJust $ findTripletProductWithSumN 1000

findTripletProductWithSumN :: Int -> Maybe Int
findTripletProductWithSumN = fmap product . findTripletWithSumN

findTripletWithSumN :: Int -> Maybe [Int]
findTripletWithSumN = findSumIsN <*> tripletList

findSumIsN :: Int -> [[Int]] -> Maybe [Int]
findSumIsN n xs
  | null f    = Nothing
  | otherwise = Just $ head f
  where
    f = filter ((n ==) . sum) $ takeWhile (any (<= n)) xs

tripletList :: Int -> [[Int]]
tripletList n = catMaybes $ gentriplet <$> [2..n] <*> [1..n-1]

gentriplet :: Int -> Int -> Maybe [Int]
gentriplet r s
  | r <= s     = Nothing
  | even (r-s) = Nothing
  | otherwise  = Just [a, b, c]
  where
    a = r * r - s * s
    b = 2 * r * s
    c = r * r + s * s
