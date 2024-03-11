# Time  : O(logn)
# Space : O(1)

class Solution:
  def singleNonDuplicate(self, A: List[int]) -> int:
    lo, hi = 0, len(A) - 1

    while lo < hi:
      mid = lo + (hi - lo) // 2
      # if mid is even
      if mid % 2 == 0:
        if A[mid] == A[mid + 1]:
          lo = mid + 2
        else:
          hi = mid
      # if mid is odd
      else:
        if A[mid - 1] == A[mid]:
          lo = mid + 1
        else:
          hi = mid - 1

    return A[lo]