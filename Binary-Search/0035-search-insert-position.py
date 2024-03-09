# Time  : O(logn)
# Space : O(1)

class Solution:
  def searchInsert(self, A: List[int], target: int) -> int:
    lo, hi = 0, len(A) - 1

    while lo <= hi:
      mid = lo + (hi - lo) // 2
      if A[mid] < target:
        lo = mid + 1
      elif A[mid] > target:
        hi = mid - 1
      else:
        return mid

    return lo

# Time  : O(logn)
# Space : O(1)

class Solution:
  def searchInsert(self, A: List[int], target: int) -> int:
    # lower bound
    lo, hi = 0, len(A)
    while lo < hi:
      mid = lo + (hi - lo) // 2
      if A[mid] < target:
        lo = mid + 1
      else:
        hi = mid
    return lo