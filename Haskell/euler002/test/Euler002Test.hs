import Test.Tasty
import Test.Tasty.HUnit

import Euler002

unitTests :: TestTree
unitTests = testGroup "Euler - 002: Unit Tests"
  [ testCase
      "First ten Fibonacci numbers should be: \
      \1, 2, 3, 5, 8, 13, 21, 34, 55, 89" $
      take 10 fibs @?=
      [1, 2, 3, 5, 8, 13, 21, 34, 55, 89]

  , testCase
      "Final Answer: Sum of even-valued Fibonacci numbers up to \
      \4,000,000 (4613732)" $
      euler002 @?= 4613732
  ]

main :: IO()
main = defaultMain unitTests
