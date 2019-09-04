import Test.Tasty
import Test.Tasty.HUnit

import Euler012

unitTests :: TestTree
unitTests = testGroup "Euler - 012: Unit Tests"
  [ testCase
      "The 7th triangle number is 28" $
      triangles !! 6 @?= 28

  , testCase
      "The first ten triangle numbers are correct" $
      take 10 triangles @?= [1, 3, 6, 10, 15, 21, 28, 36, 45, 55]

  , testCase
      "The first triangle number to have over five divisors is 28" $
      triangleNumberOverNFactors 5 @?= 28

  , testCase
      "Final Answer: The first triangle number to have over 500 divisors is 76576500" $
      euler012 @?= 76576500
  ]

main :: IO()
main = defaultMain unitTests
