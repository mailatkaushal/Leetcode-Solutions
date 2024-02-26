# Time  : O(n)
# Space : O(1)

class Solution:
  def maximumScore(self, A: List[int], k: int) -> int:
    # Expand the window towards the greater element as it may provide the largest minimum element in the subarray and give the maximum result.

    n = len(A)
    mi = A[k]
    res = A[k]
    i = k
    j = k

    while i > 0 or j < n - 1:
      if i == 0:                 # i exhausted, expand right
        mi = min(mi, A[j + 1])
        j += 1
      elif j == n-1:             # j exhausted, expand left
        mi = min(mi, A[i - 1])
        i -= 1
      elif A[i - 1] < A[j + 1]:  # expand right
        mi = min(mi, A[j + 1])
        j += 1
      else:                      # expand left
        mi = min(mi, A[i - 1])
        i -= 1
        
      res = max(res, mi * (j - i + 1))
    
    return res