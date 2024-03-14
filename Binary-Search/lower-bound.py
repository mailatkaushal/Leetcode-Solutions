def lowerBound(A: [int], n: int, x: int) -> int:
  lo, hi = 0, n
  while lo < hi:
    mid = lo + (hi - lo) // 2
    if A[mid] < x:
      lo = mid + 1
    else:
      hi = mid
  return lo