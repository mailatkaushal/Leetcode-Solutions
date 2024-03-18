# Time  : O(logn)
# Space : O(1)

class Solution:
  def findInMountainArray(self, x: int, A: 'MountainArray') -> int:
    # find peak
    n = A.length()
    lo, hi = 0, n - 1
    while lo < hi:
      mid = lo + (hi - lo) // 2
      if A.get(mid) < A.get(mid + 1):
        lo = mid + 1
      else:
        hi = mid
    peak = lo
    
    # search in left part
    lo, hi = 0, peak
    while lo <= hi:
      mid = lo + (hi - lo) // 2
      if A.get(mid) < x:
        lo = mid + 1
      elif A.get(mid) > x:
        hi = mid - 1
      else:
        return mid
    
    # search in right part
    lo, hi = peak + 1, n - 1
    while lo <= hi:
      mid = lo + (hi - lo) // 2
      if A.get(mid) < x:
        hi = mid - 1
      elif A.get(mid) > x:
        lo = mid + 1
      else:
        return mid
    
    return -1