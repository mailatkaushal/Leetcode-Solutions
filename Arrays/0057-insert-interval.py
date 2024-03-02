# Time  : O(n)
# Space : O(n)

class Solution:
  def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
    res = []

    for interval in intervals:
      # Non-overlapping 
      # interval comes before newInterval. Add interval to res
      if interval[1] < newInterval[0]:
        res.append(interval)
        
      # Non-overlapping
      # newInterval comes before interval. Add newInterval to res. Now, newInterval becomes interval
      elif newInterval[1] < interval[0]:
        res.append(newInterval)
        newInterval = interval

      # Overlapping
      else:
        # update the newInterval
        newInterval[0] = min(interval[0], newInterval[0])
        newInterval[1] = max(interval[1], newInterval[1])

    # Add the last non-overlapping interval(newInterval)
    res.append(newInterval)

    return res