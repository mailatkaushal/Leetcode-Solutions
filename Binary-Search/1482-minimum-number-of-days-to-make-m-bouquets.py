# Time  : O(nlogm) - Where n is len(bloomDay), m is the (max - min) in bloomDay
# Space : O(1)

class Solution:
  def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
    # return minimum number of days to make m bouquests otherwise if impossible return -1

    n = len(bloomDay)
    if m * k > n:
      return -1
      
    ma = float('-inf')
    mi = float('inf')
    for day in bloomDay:
      ma = max(ma, day)
      mi = min(mi, day)

    lo, hi = mi, ma

    while lo <= hi:
      day = lo + (hi - lo) // 2

      # number of bouqets that can be made
      bouqs = 0
      wcnt, wsize = 0, 0
      for i in range(n):
        if bloomDay[i] <= day:
          wcnt += 1
        else:
          bouqs += wcnt // k
          wcnt = 0
      bouqs += wcnt // k

      if bouqs < m:
        lo = day + 1
      else:
        hi = day - 1
    
    return lo