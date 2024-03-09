# Time  : O(m + n)
# Space : O(1)

class Solution:
  def getCommon(self, A: List[int], B: List[int]) -> int:
    i, j = 0, 0

    while i < len(A) and j < len(B):
      if A[i] == B[j]:
        return A[i]
      elif A[i] < B[j]:
        i += 1
      else:
        j += 1

    return -1