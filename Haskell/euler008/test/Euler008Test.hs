import Test.Tasty
import Test.Tasty.HUnit

import Euler008

unitTests :: TestTree
unitTests = testGroup "Euler - 008: Unit Tests"
  [ testCase
      "The four adjacent digits in the 1000-digit number that have the \
      \greatest product are 9 × 9 × 8 × 9 = 5832" $
        maxProductOfSlicesInSeries 4 @?= 5832

  , testCase
      "Final Answer: The product of the thirteen adjacent digits in the \
      \1000-digit number that have the greatest product is 23514624000" $
      euler008 @?= 23514624000
  ]

main :: IO()
main = defaultMain unitTests
