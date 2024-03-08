# Time  : O(m + logn)
# Space : O(1)

class Solution:
  def searchMatrix(self, M: List[List[int]], target: int) -> bool:
    m, n = len(M), len(M[0])

    def binarySearch(A):
      lo, hi = 0, n - 1
      while lo <= hi:
        mid = (lo + hi) // 2
        if A[mid] == target:
          return True
        elif A[mid] < target:
          lo = mid + 1
        else:
          hi = mid-1
      return False

    for i in range(m):
      if M[i][0] <= target <= M[i][n-1]:
        return binarySearch(M[i])
    return False
  
# Time  : O(log(m*n))
# Space : O(1)

class Solution:
  def searchMatrix(self, M: List[List[int]], target: int) -> bool:
    m, n = len(M), len(M[0])
    lo, hi = 0, m * n - 1

    while lo <= hi:
      mid = (lo + hi) // 2
      x = mid // n
      y = mid % n
      if M[x][y] == target:
        return True
      elif M[x][y] < target:
        lo = mid + 1
      else:
        hi = mid - 1

    return False