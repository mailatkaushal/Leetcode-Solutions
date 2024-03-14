# Lower bound - finds the first index where the value at that index is greater than or equal to target

def lowerBound(A: [int], n: int, x: int) -> int:
    lo, hi = 0, n - 1
    lb = n
    while lo <= hi:
      mid = lo + (hi - lo) // 2
      if A[mid] < x:
        lo = mid + 1
      else:
        lb = mid
        hi = mid - 1     
    return lb

def lowerBound(A: [int], n: int, x: int) -> int:
  lo, hi = 0, n
  while lo < hi:
    mid = lo + (hi - lo) // 2
    if A[mid] < x:
      lo = mid + 1
    else:
      hi = mid
  return lo