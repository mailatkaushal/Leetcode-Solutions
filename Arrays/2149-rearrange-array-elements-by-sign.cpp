// Time  : O(n)
// Space : O(n)

class Solution:
  def rearrangeArray(self, A: List[int]) -> List[int]:
    n = len(A)
    res = [0] * n
    
    pos, neg = 0, 1

    for a in A:
      if a > 0:
        res[pos] = a
        pos += 2
      else:
        res[neg] = a
        neg += 2
    
    return res