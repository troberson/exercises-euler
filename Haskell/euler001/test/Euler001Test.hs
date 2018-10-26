import Test.Tasty
import Test.Tasty.HUnit

import Euler001

unitTests :: TestTree
unitTests = testGroup "Euler - 001: Unit Tests"
  [ 10 `shouldEqual` 23
  , 1000 `shouldEqual` 233168
  , testCase "Final Answer (233168)" $ euler001 @?= 233168
  ]
  where
    shouldEqual n result = testCase desc $
      sumMultiples [3, 5] [1..n-1] @?= result
      where
        desc = "Sum of natural numbers below " ++ show n ++
               " that are multiples of 3 or 5 (" ++ show result ++ ")"

main :: IO()
main = defaultMain unitTests
