import Test.Tasty
import Test.Tasty.HUnit

import Euler001

unitTests :: TestTree
unitTests = testGroup "Euler - 001: Unit Tests"
  [ testCase
      "The natural numbers below 10 that are multiples of 3 or 5 are \
      \3, 5, 6 and 9" $
      filterMultiples [3, 5] [1..9] @?= [3, 5, 6, 9] 

  , testCase
      "The sum of the natural numbers below 10 that are multiples of 3 or 5 \
      \is 23" $
      sumMultiples [3, 5] [1..9] @?= 23
      
  , testCase
      "Final Answer: The sum of all the multiples of 3 or 5 below 1000 is \
      \233168" $
      euler001 @?= 233168
  ]

main :: IO()
main = defaultMain unitTests
