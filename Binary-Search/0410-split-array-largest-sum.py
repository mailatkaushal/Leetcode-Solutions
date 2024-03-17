# Time  : O(nlogm) - Where n is len(A), m is sum(A) - max(A)
# Space : O(1)

class Solution:
  def splitArray(self, A: List[int], k: int) -> int:
    n = len(A)

    def canPartition(max_sum):
      partitions = 1
      sum = 0
      for n in A:
        if sum + n <= max_sum:
          sum += n
        else:
          partitions += 1
          if partitions > k:
            return False
          sum = n
      return True

    lo, hi = max(A), sum(A)

    while lo <= hi:
      max_sum = lo + (hi - lo) // 2
      if canPartition(max_sum):
        hi = max_sum - 1
      else:
        lo = max_sum + 1
    
    return lo