-- Project Euler - 006 - Sum Square Difference
--
-- The sum of the squares of the first ten natural numbers is,
--   1^2 + 2^2 + ... + 10^2 = 385
--
-- The square of the sum of the first ten natural numbers is,
--   (1 + 2 + ... + 10)^2 = 55^2 = 3025
--
-- Hence the difference between the sum of the squares of the first ten natural
-- numbers and the square of the sum is 3025 − 385 = 2640.
--
-- Find the difference between the sum of the squares of the first one hundred
-- natural numbers and the square of the sum.

module Euler006 (euler006, sumOfSquares, squareOfSum, sumSquareDifference) where

euler006 :: Integer
euler006 = sumSquareDifference [1..100]

sumSquareDifference :: [Integer] -> Integer
sumSquareDifference = (-) <$> squareOfSum <*> sumOfSquares

squareOfSum :: [Integer] -> Integer
squareOfSum = square . sum

sumOfSquares :: [Integer] -> Integer
sumOfSquares = sum . map square

-- avoids the implicit cast issue with the numeric literal in x^2
square :: Integer -> Integer
square x = x * x
