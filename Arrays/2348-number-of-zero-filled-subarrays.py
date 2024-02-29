# Maths
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

  '''
    Ex. A = [1,3,0,2,0,0,4,0,0,0]
        cnt = 10

        [0]      -> will add 1 zero-filled subarr
        [0]

        [0,0]    -> will add 3 zero-filled subarrs 
        [0]
          [0]
        [0,0]

        [0,0,0]  -> will add 6 zero-filled subarrs
        [0]
          [0]
            [0]
        [0,0]
          [0,0]
        [0,0,0]
        
  '''
  
# Observation
# Time  : O(n)
# Space : O(1)
  
class Solution:
  def zeroFilledSubarray(self, A: List[int]) -> int:
    cnt = 0
    tmp = 0
    
    for n in A:
      if n == 0:
        tmp += 1
        cnt += tmp
      else:
        tmp = 0

    return cnt