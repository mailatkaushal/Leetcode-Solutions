# Time  : O(nlogn)
# Space : O(logn)

class Solution:
  def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
    n = len(intervals)
    intervals.sort()
    res = 0

    for i in range(1, n):
      if intervals[i - 1][1] <= intervals[i][0]:    # prev_end <= curr_start  ----- -----
        continue
      # overlapping
      elif intervals[i - 1][1] <= intervals[i][1]:  # prev_end <= curr_end  -----     or  ----- 
        res += 1                                    #                          -----        ---
        intervals[i][1] = intervals[i - 1][1]
      else:                                         # prev_end > curr_end  -----
        res += 1                                    #                       ---

    return res