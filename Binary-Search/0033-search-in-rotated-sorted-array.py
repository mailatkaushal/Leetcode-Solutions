# Time  : O(logn)
# Space : O(1)

class Solution:
  def search(self, A: List[int], target: int) -> int:
    n = len(A)

    def getPivot():  # minimum element
      lo, hi = 0, n - 1
      while lo < hi:
        mid = lo + (hi - lo) // 2
        if A[0] <= A[mid]:
          lo = mid + 1
        else:
          hi = mid
      return lo

    def binarySearch(lo, hi):
      while lo <= hi:
        mid = lo + (hi - lo) // 2
        if A[mid] < target:
          lo = mid + 1
        elif A[mid] > target:
          hi = mid - 1
        else:
          return mid
      return -1

    pivot = getPivot()

    if A[pivot] <= target <= A[n - 1]:
      return binarySearch(pivot, n - 1)
    else:
      return binarySearch(0, pivot - 1)

# Time  : O(logn)
# Space : O(1)

class Solution:
  def search(self, A: List[int], target: int) -> int:
    lo, hi = 0, len(A) - 1

    while lo <= hi:
      mid = lo + (hi - lo) // 2
      if A[mid] == target:
        return mid
      # left half is sorted
      if A[lo] <= A[mid]:
        # target is in left half
        if A[lo] <= target < A[mid]:
          hi = mid - 1
        else:
          lo = mid + 1
      # right half is sorted
      else:
        # target is in right half
        if A[mid] < target <= A[hi]:
          lo = mid + 1
        else:
          hi = mid - 1

    return -1