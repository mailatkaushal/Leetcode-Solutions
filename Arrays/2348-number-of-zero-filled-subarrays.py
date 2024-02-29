# Time  : O(n)
# Space : O(1)

class Solution:
  def zeroFilledSubarray(self, A: List[int]) -> int:
    n = len(A)
    cnt = 0
    i = 0

    while i < n:
      zeroes = 0
      if A[i] == 0:
        zeroes += 1 
        i += 1
        while i < n and A[i] == 0:
          zeroes += 1
          i += 1
      else:
        i += 1
      cnt += zeroes * (zeroes + 1) // 2

    return cnt