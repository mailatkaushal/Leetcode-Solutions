# Time  : O(m * logn)
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
        if binarySearch(M[i]) == True:
          return True

    return False
  
# Time  : O(m+n)
# Space : O(1)
  
class Solution:
  def searchMatrix(self, M: List[List[int]], target: int) -> bool:
    m, n = len(M), len(M[0])
    i, j = 0, n - 1

    while i < m and j >= 0:
      if M[i][j] < target:
        # target can not be in entire row bc the row is sorted
        i += 1
      elif M[i][j] > target:
        # target can not be in entire col bc the col is sorted
        j -= 1
      else:
        return True

    return False