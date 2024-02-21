class Solution:
  def rangeBitwiseAnd(self, left: int, right: int) -> int:
    # TLE
    # res = left
    # for i in range(left + 1, right + 1):
    #   res &= i
    # return res

    # Bitwise-AND of any two numbers will always produce a number less than or equal to the smaller number

    # 12 -> 1100
    # 11 -> 1011
    # 10 -> 1010
    # 9  -> 1001
    # 8  -> 1000
    # 7  -> 0111
    # 6  -> 0110
    # 5  -> 0101

    # Range : [5, 12]

    # iteration 1:
    # 12 & 11 = 8

    # iteration 2:
    # 8 & 7 = 0

    # why skip 10, 9?  Because even if we did so, the result would eventually be anded with 8 whose value would be lesser than equal to 8.

    while right > left:
      # set rightmost 1 to 0
      right = right & (right - 1)
    
    return right

    # Time  : O(32) ~ O(1)
    # Space : O(1)

# Time  : O(32) ~ O(1)
# Space : O(1)

class Solution:
  def rangeBitwiseAnd(self, left: int, right: int) -> int:
    shift_count = 0

    while (left != right):
      left >>= 1
      right >>= 1
      shift_count += 1

    return left << shift_count