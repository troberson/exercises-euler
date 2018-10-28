import Test.Tasty
import Test.Tasty.HUnit

import Euler004

unitTests :: TestTree
unitTests = testGroup "Euler - 004: Unit Tests"
  [ testCase "9009 is a Palindrome (True)" $ isPalindrome 9009 @?= True
  , testCase "1234 is not a palindrome (False)" $ isPalindrome 1234 @?= False
  , testCase
      "Largest palindrome made from the product of two 2-digit numbers (9009)" $
      largestPalindromeProduct [10..99] @?= 9009
  , testCase
      "Final Answer: Largest palindrome made from the product of two 3-digit \
      \numbers (906609)" $
      euler004 @?= 906609
  ]

main :: IO()
main = defaultMain unitTests
