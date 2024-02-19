// Time  : O(n)
// Space  : O(1)

class Solution:
  def sortArrayByParity(self, A: List[int]) -> List[int]:
    # put even integers ahead
    l, r = 0, len(A) - 1

    while l < r:
      if A[l] & 1 == 1:
        A[l], A[r] = A[r], A[l]
        r -= 1
      else:
        l += 1

    return A