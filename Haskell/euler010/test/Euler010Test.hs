import Test.Tasty
import Test.Tasty.HUnit

import Euler010

unitTests :: TestTree
unitTests = testGroup "Euler - 010: Unit Tests"
  [ testCase
      "The primes below 10 are 2, 3, 5, and 7" $
      primesToN 10 @?= [2, 3, 5, 7]

  , testCase
      "The sum of the primes below 10 is 17" $
      sumPrimesToN 10 @?= 17

  , testCase
      "Final Answer: The sum of all the primes below two million is \
      \142913828922" $
      euler010 @?= 142913828922
  ]

main :: IO()
main = defaultMain unitTests
