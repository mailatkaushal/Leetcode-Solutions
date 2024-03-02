# Time  : O(n)
# Space : O(n)

class Solution:
  def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
    n = len(intervals)
    i = 0
    res = []

    # Case 1: Non-overlapping intervals before newInterval
    while i < n and intervals[i][1] < newInterval[0]:
      res.append(intervals[i])
      i += 1

    # Case 2: Overlapping, merging interval and newInterval
    while i < n and newInterval[1] >= intervals[i][0]:
      newInterval[0] = min(intervals[i][0], newInterval[0])
      newInterval[1] = max(intervals[i][1], newInterval[1])
      i += 1
    
    # Add the non-overlapping newInterval
    res.append(newInterval)

    # Case 3: Non-overlapping intervals after newInterval added
    while i < n:
      res.append(intervals[i])
      i += 1

    return res

    '''
    Case 1:
      ________    ________
         i          newI

    Case 2: 

         i                        i               i
      ________                 ________        ________  
          ________     ________            ________
            newI         newI                newI

    Case 3:

        newI         i
      ________    ________
    
    '''