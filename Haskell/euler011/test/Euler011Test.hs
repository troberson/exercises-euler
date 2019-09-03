import Test.Tasty
import Test.Tasty.HUnit

import Euler011

unitTests :: TestTree
unitTests = testGroup "Euler - 011: Unit Tests"
  [ testCase
     "Final Answer: The greatest product of four adjacent numbers in the same \
     \direction in the 20×20 grid is 70600674." $
     euler011 @?= 70600674
  ]

main :: IO()
main = defaultMain unitTests
