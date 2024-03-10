# Time  : O(logn) -> O(n)
# Space : O(1)

class Solution:
  def search(self, A: List[int], target: int) -> bool:
    n = len(A)

    def getPivot():
      lo, hi = 0, n - 1
      while lo < hi:
        while (lo < hi and A[lo] == A[lo + 1]):
          lo += 1
        while (lo < hi and A[hi - 1] == A[hi]):
          hi -= 1
        # [2,2,3,2,2,2,2]
        # lo     m     hi
        # Here, A[0] <= A[mid] 
        # and we'll ignore left half but pivot lies there..
        # so, ignore duplicates
        
        mid = lo + (hi - lo) // 2
        if A[mid] > A[hi]:
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
          return True
      return False

    pivot = getPivot()

    if A[pivot] <= target <= A[n - 1]:
      return binarySearch(pivot, n - 1)
    else:
      return binarySearch(0, pivot - 1)

# Time  : O(logn) -> O(n)
# Space : O(1)

class Solution:
  def search(self, A: List[int], target: int) -> bool:
    lo, hi = 0, len(A) - 1

    while lo <= hi:
      mid = lo + (hi - lo) // 2
      if A[mid] == target:
        return True
      # fail to estimate which side is sorted 
      if A[lo] == A[mid] == A[hi]:
        lo += 1
        hi -= 1
        continue
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

    return False