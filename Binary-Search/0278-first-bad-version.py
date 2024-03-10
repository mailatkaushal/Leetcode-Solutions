# Time  : O(logn)
# Space : O(1)

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
  def firstBadVersion(self, n: int) -> int:
    # lower bound
    lo, hi = 1, n

    while lo < hi:
      mid = lo + (hi - lo) // 2
      if isBadVersion(mid) == False:
        lo = mid + 1
      else:
        hi = mid

    return lo