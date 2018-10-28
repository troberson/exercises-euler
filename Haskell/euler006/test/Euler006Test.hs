import Test.Tasty
import Test.Tasty.HUnit

import Euler006

unitTests :: TestTree
unitTests = testGroup "Euler - 006: Unit Tests"
  [ testCase
      "The sum of the squares of the first ten natural numbers is 385" $
      sumOfSquares [1..10] @?= 385

  , testCase
      "The square of the sum of the first ten natural numbers is 3025" $
      squareOfSum [1..10] @?= 3025

  , testCase
      "The difference between the sum of the squares of the first ten natural \
      \numbers and the square of the sum is 2640" $
      sumSquareDifference [1..10] @?= 2640

  , testCase
      "Final Answer: The difference between the sum of the squares of the \
      \first one hundred natural numbers and the square of the sum is \
      \25164150" $
      euler006 @?= 25164150
  ]

main :: IO()
main = defaultMain unitTests
