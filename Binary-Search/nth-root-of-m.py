# Time  : O(logn)
# Space : O(1)

def NthRoot(n: int, m: int) -> int:
  lo, hi = 1, m

  while lo <= hi:
    mid = lo + (hi - lo) // 2
    if mid ** n < m:
      lo = mid + 1
    elif mid ** n > m:
      hi = mid - 1
    else:
      return mid
      
  return -1