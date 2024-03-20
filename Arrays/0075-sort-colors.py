# Time  : O(n)
# Space : O(1)

class Solution:
  def sortColors(self, A: List[int]) -> None:
    # Do not return anything, modify nums in-place instead.
    i, j, k = 0, 0, len(A) - 1

    while j <= k:
      if A[j] == 0:
        A[i], A[j] = A[j], A[i]
        i += 1
        j += 1
      elif A[j] == 1:
        j += 1
      else:
        A[j], A[k] = A[k], A[j]
        k -= 1