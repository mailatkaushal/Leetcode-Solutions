# Time  : O(logn)
# Space : O(1)

class Solution:
  def search(self, A: List[int], target: int) -> int:
    lo, hi = 0, len(A) - 1

    while lo <= hi:
      mid = lo + (hi - lo) // 2
      if A[mid] < target:
        lo = mid + 1
      elif A[mid] > target:
        hi = mid - 1
      else:
        return mid

    return -1