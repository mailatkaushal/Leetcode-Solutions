# Time  : O(nlogm) - Where n is len(piles), m is the max in piles 
# Space : O(1)

class Solution:
  def minEatingSpeed(self, piles: List[int], h: int) -> int:
    # return the min integer k(bananas/hour) such that Koko can eat all bananas within h hours
    lo, hi = 1, max(piles)

    while lo < hi:
      k = lo + (hi - lo) // 2
      hours = 0
      for p in piles:
        hours += math.ceil(p / k)
      if hours > h:
        lo = k + 1
      else:
        hi = k
        
    return lo