import Test.Tasty
import Test.Tasty.HUnit

import EulerXXX

unitTests :: TestTree
unitTests = testGroup "Euler - XXX: Unit Tests"
  [
--   testCase "Final Answer ()" $ eulerXXX @?= 0
  ]
  where
    shouldEqual n result = testCase desc $ id n @?= result
      where
        desc = ""

main :: IO()
main = defaultMain unitTests
