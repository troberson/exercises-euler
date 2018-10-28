import Test.Tasty
import Test.Tasty.HUnit

import EulerXXX

unitTests :: TestTree
unitTests = testGroup "Euler - XXX: Unit Tests"
  [ testCase
      "Foo" $
      id 0 @?= 0

--  , testCase
--      "Final Answer:" $
--      eulerXXX @?= 0
  ]

main :: IO()
main = defaultMain unitTests
