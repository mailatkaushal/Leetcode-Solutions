// Time  : O(logn)
// Space : O(1)

class Solution:
  def isPowerOfTwo(self, n: int) -> bool:
    x = 1
    while x < n:
      x *= 3
    return x == n

// Time  : O(1)
// Space : O(1)

class Solution:
  def isPowerOfThree(self, n: int) -> bool:
    if n <= 0:
      return False

    return 1162261467 % n == 0  #  3^19 = 1162261467