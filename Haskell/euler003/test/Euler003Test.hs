import Test.Tasty
import Test.Tasty.HUnit

import Euler003

unitTests :: TestTree
unitTests = testGroup "Euler - 003: Unit Tests"
  [ testCase
      "The prime factors of 13195 are 5, 7, 13 and 29." $
      primeFactors 13195 @?= [5, 7, 13, 29]

  , testCase
      "Final Answer: The largest prime factor of the number \
      \600851475143 (6857)" $
      euler003 @?= 6857
  ]

main :: IO()
main = defaultMain unitTests
