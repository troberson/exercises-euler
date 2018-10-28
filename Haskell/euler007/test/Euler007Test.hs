import Test.Tasty
import Test.Tasty.HUnit

import Euler007

unitTests :: TestTree
unitTests = testGroup "Euler - 007: Unit Tests"
  [ testCase
      "The first six prime numbers are 2, 3, 5, 7, 11 and 13" $
      primesFirstN 6 @?= [2, 3, 5, 7, 11, 13]

  , testCase
      "The 6th prime is 13" $
      primeNth 6 @?= 13

  , testCase
      "Final Answer: The 10,001st prime number is 104,743" $
      euler007 @?= 104743
  ]

main :: IO()
main = defaultMain unitTests
