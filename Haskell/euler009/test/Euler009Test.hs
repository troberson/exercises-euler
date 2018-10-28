import Test.Tasty
import Test.Tasty.HUnit

import Euler009

unitTests :: TestTree
unitTests = testGroup "Euler - 009: Unit Tests"
  [ testCase
      "A 3-4-5 Pythagorean triplet has a sum of 12" $
      findTripletWithSumN 12 @?= Just [3, 4, 5]

  , testCase
      "A 3-4-5 Pythagorean triplet has a sum of 12 and a product of 60" $
      findTripletProductWithSumN 12 @?= Just 60

  , testCase
      "Final Answer (A): 375-200-425 is a Pythagorean triplet for which \
      \a + b + c = 1000" $
      findTripletWithSumN 1000 @?= Just [375, 200, 425]

  , testCase
      "Final Answer (B): The product abc of the Pythagorean triplet for which \
      \a + b + c = 1000 is 31875000" $
      euler009 @?= 31875000
  ]

main :: IO()
main = defaultMain unitTests
