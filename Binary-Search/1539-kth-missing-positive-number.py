# Time  : O(n)
# Space : O(1)

class Solution:
  def findKthPositive(self, A: List[int], k: int) -> int:
    n = len(A)
    num = 1
    i = 0
    
    while i < n:
      if num == A[i]:
        i += 1
      else:
        k -= 1
        if k == 0:
          return num
      num += 1
    
    return A[n-1] + k

# Time  : O(logn)
# Space : O(1)

class Solution:
  def findKthPositive(self, A: List[int], k: int) -> int:
    n = len(A)
    lo, hi = 0, n - 1

    while lo <= hi:
      mid = lo + (hi - lo) // 2
      missing = A[mid] - (mid + 1)
      if missing < k:
        lo = mid + 1
      else:
        hi = mid - 1
    
    return k + hi + 1

    # return A[hi] + (k - missing)  # hi can be -1 in cases such as A = [2,3,4], k = 1
    # A[hi] + k - (A[hi] - (hi + 1))
    # A[hi] + k - A[hi] + hi + 1
    # k + hi + 1 or k + lo