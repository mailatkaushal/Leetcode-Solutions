# Time  : O(logn)
# Space : O(1)

class Solution:
  def findMin(self, A: List[int]) -> int:
    lo, hi = 0, len(A) - 1

    while lo < hi:
      mid = lo + (hi - lo) // 2
      if A[mid] > A[hi]:
        lo = mid + 1
      elif A[mid] < A[hi]:
        hi = mid
      else:  # A[mid] == A[hi]
        if hi > 0 and A[hi - 1] <= A[hi]:
          hi -= 1
        else:
          break

    return A[hi]