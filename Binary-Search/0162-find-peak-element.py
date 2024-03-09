# Time  : O(logn)
# Space : O(1)

class Solution:
  def findPeakElement(self, A: List[int]) -> int:
    n = len(A)

    if n == 1:
      return 0
    if A[0] > A[1]:
      return 0
    if A[n-2] < A[n-1]:
      return n-1

    lo, hi = 1, n - 2

    while lo <= hi:
      mid = lo + (hi - lo) // 2
      if A[mid - 1] < A[mid] > A[mid + 1]:  
        return mid
      elif A[mid] < A[mid + 1]:
        lo = mid + 1
      else:
        hi = mid - 1

# Time  : O(logn)
# Space : O(1)

class Solution:
  def findPeakElement(self, A: List[int]) -> int:
    lo, hi = 0, len(A) - 1

    while lo < hi:
      mid = lo + (hi - lo) // 2
      if A[mid] < A[mid + 1]:
        lo = mid + 1
      else:
        hi = mid

    return lo