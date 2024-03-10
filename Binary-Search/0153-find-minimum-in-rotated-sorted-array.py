# Time  : O(logn)
# Space : O(1)

class Solution:
  def findMin(self, A: List[int]) -> int:  # pivot
    lo, hi = 0, len(A) - 1

    while lo < hi:
      mid = lo + (hi - lo) // 2
      if A[mid] > A[hi]:
        lo = mid + 1
      else:
        hi = mid

    return A[lo]