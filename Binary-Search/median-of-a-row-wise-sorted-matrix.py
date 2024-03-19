# Time  : O(m*n + m*nlog(m*n))
# Space : O(logn(m*n)) - bc of sorting

def median(M: [[int]], m: int, n: int) -> int:
  v = [0] * (m * n)
  x = 0
  for i in range(m):
    for j in range(n):
      v[x] = M[i][j]
      x += 1
  v.sort()
  return v[m * n // 2]

# Time  : O(log(1e9) * mlogn)
# Space : O(1)

def median(M: [[int]], m: int, n: int) -> int:
    lo, hi = 1, 1000000000
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        cnt = 0
        for i in range(m):
            cnt += countSmallerThanOrEqualMid(M[i], mid)
        if cnt <= m*n//2:
            lo = mid + 1
        else:
            hi = mid - 1
    return lo

def countSmallerThanOrEqualMid(row, mid):  # upper bound
    lo, hi = 0, len(row) - 1
    while lo <= hi:
        md = lo + (hi - lo) // 2
        if row[md] <= mid:
            lo = md + 1
        else:
            hi = md - 1
    return lo