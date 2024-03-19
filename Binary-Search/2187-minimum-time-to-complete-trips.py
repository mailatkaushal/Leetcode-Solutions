# Time  : O(nlogm) - Where n is len(time), m is the min in time * totalTrips 
# Space : O(1)

class Solution:
  def minimumTime(self, time: List[int], totalTrips: int) -> int:
    lo, hi = 1, min(time) * totalTrips

    while lo <= hi:
      mid_time = lo + (hi - lo) // 2
      trips = 0
      for t in time:
        trips += mid_time // t
      if trips < totalTrips:
        lo = mid_time + 1
      else:
        hi = mid_time - 1
    
    return lo