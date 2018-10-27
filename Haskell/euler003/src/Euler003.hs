-- Project Euler - 003 - Largest Prime Factor
--
-- The prime factors of 13195 are 5, 7, 13 and 29.
-- What is the largest prime factor of the number 600851475143 ?

-- TODO: These recursion patterns probably have standard versions.
-- doRecursive is somewhat like foldr.
-- doRecursiveSmart is somewhat like unfoldr.

module Euler003 (euler003, primeFactors) where

euler003 :: Integer
euler003 = largestPrimeFactor 600851475143

largestPrimeFactor :: Integer -> Integer
largestPrimeFactor n = getLast $ primeFactors n
  where
    getLast [] = 1
    getLast xs = last xs

primeFactors :: Integer -> [Integer]
primeFactors n = n `factorUsing` primes

-- |factorUsing: Finds which of a given list of numbers are factors of the
-- |number (useful for prime factors).
factorUsing :: Integer -> [Integer] -> [Integer]
factorUsing n = doRecursiveSmart n isDiv div (<)

-- This is a very naive primes algorithm but it works for our purposes.
primes :: [Integer]
primes = doRecursive (filter . flip notDiv) [2..]

-- |doRecursive: Apply a function which operates on a list recursively to the
-- |tail of a list, keeping the head each time.
doRecursive :: (a -> [a] -> [a]) -> [a] -> [a]
doRecursive f (x:xs) = x : doRecursive f (f x xs)

-- |doRecursiveSmart: Build a list efficiently by supplying a function for the
-- |next value to possibly add to the result list based on the current value.
-- |Takes a value (a), a function to test whether or not that value should be added
-- |to the result list (a -> a -> Bool), a function which provides the next
-- |value to test (a -> a -> a), a function determining when to
-- |stop (a -> a -> Bool), and a list ([a]).
doRecursiveSmart :: a                -- Value
                 -> (a -> a -> Bool) -- Test Function
                 -> (a -> a -> a)    -- Next Function
                 -> (a -> a -> Bool) -- Stop Function
                 -> [a]              -- List
                 -> [a]              -- Result
doRecursiveSmart x test next stop (y:ys)
    | stop x y  = []
    | test x y  = y : doRecursiveSmart (next x y) test next stop (y:ys)
    | otherwise = doRecursiveSmart x test next stop ys

isDiv :: Integral a => a -> a -> Bool
isDiv n d = n `rem` d == 0

notDiv :: Integral a => a -> a -> Bool
notDiv = (not .). isDiv
