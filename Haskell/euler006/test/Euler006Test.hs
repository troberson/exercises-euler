import Test.Tasty
import Test.Tasty.HUnit

import Euler006

unitTests :: TestTree
unitTests = testGroup "Euler - 006: Unit Tests"
  [ testCase
      "Sum of the squares of the first ten natural numbers (385)" $
      sumOfSquares [1..10] @?= 385

  , testCase
      "Square of the sum of the first ten natural numbers (3025)" $
      squareOfSum [1..10] @?= 3025

  , testCase
      "Difference between the sum of the squares of the first ten natural \
      \numbers and the square of the sum (2640)" $
      sumSquareDifference [1..10] @?= 2640

  , testCase
      "Final Answer: Difference between the sum of the squares of the first \
      \one hundred natural numbers and the square of the sum (25164150)" $
      euler006 @?= 25164150
  ]

main :: IO()
main = defaultMain unitTests
