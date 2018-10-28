-- Project Euler - 004 - Largest palindrome product
--
-- A palindromic number reads the same both ways. The largest palindrome made
-- from the product of two 2-digit numbers is 9009 = 91 × 99.
--
-- Find the largest palindrome made from the product of two 3-digit numbers.

module Euler004 (euler004, largestPalindromeProduct, isPalindrome) where

euler004 :: Integer
euler004 = largestPalindromeProduct [100..999]

largestPalindromeProduct :: [Integer] -> Integer
largestPalindromeProduct = maximum . palindromes . products

palindromes :: [Integer] -> [Integer]
palindromes = filter isPalindrome

products :: [Integer] -> [Integer]
products xs = [x * y | x <- xs, y <- xs, x <= y]

isPalindrome :: Show a => a -> Bool
isPalindrome = (==) <$> show <*> (reverse . show)
