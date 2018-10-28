import Test.Tasty
import Test.Tasty.HUnit

import Euler002

unitTests :: TestTree
unitTests = testGroup "Euler - 002: Unit Tests"
  [ testCase
      "The first ten Fibonacci numbers are \
      \1, 2, 3, 5, 8, 13, 21, 34, 55 and 89" $
      take 10 fibs @?=
      [1, 2, 3, 5, 8, 13, 21, 34, 55, 89]

  , testCase
      "Final Answer: The sum of the even-valued Fibonacci numbers whose values \
      \do not exceed four million is 4613732" $
      euler002 @?= 4613732
  ]

main :: IO()
main = defaultMain unitTests
