# Upper Bound - finds the first index where the value at that index is greater than to target

def upperBound(A: [int], x: int, n: int) -> int:
  lo, hi = 0, n - 1
  ub = n
  while lo <= hi:
    mid = lo + (hi - lo) // 2
    if A[mid] <= x:
      lo = mid + 1
    else:
      ub = mid
      hi = mid - 1
  return ub

def upperBound(A: [int], x: int, n: int) -> int:
  lo, hi = 0, n
  while lo < hi:
    mid = lo + (hi - lo) // 2
    if A[mid] <= x:
      lo = mid + 1
    else:
      hi = mid
  return lo