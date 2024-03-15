# Time  : O(nlogm) - Where n is len(weights), m is the (sum - max) in weights
# Space : O(1)

class Solution:
  def shipWithinDays(self, weights: List[int], days: int) -> int:
    lo, hi = max(weights), sum(weights)

    while lo < hi:
      cap = lo + (hi - lo) // 2

      # number of days to ship
      d = 1
      cnt = 0
      for i in range(len(weights)):
        if cnt + weights[i] <= cap:
          cnt += weights[i]
        else:
          d += 1
          cnt = weights[i]

      if d > days:
        lo = cap + 1
      else:
        hi = cap

    return lo