import Test.Tasty
import Test.Tasty.HUnit

import Euler005

unitTests :: TestTree
unitTests = testGroup "Euler - 005: Unit Tests"
  [ testCase
      "The smallest number that can be divided by each of the numbers from \
      \1 to 10 without any remainder (2520)" $ lcmList [1..10] @?= 2520

  , testCase
      "Final Answer: The smallest positive number that is evenly divisible by \
      \all of the numbers from 1 to 20 (232792560)" $ euler005 @?= 232792560
  ]

main :: IO()
main = defaultMain unitTests
