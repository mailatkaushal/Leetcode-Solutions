# Time  : O(n^2)
# Space : O(1)

class Solution:
  def pivotInteger(self, n: int) -> int:
    for i in range(1, n + 1):
      left_sum = 0
      right_sum = 0
      for j in range(1, i + 1):
        left_sum += j
      for j in range(i, n + 1):
        right_sum += j
      if left_sum == right_sum:
        return i
    return -1

# Time  : O(n)
# Space : O(1)

class Solution:
  def pivotInteger(self, n: int) -> int:
    total_sum = n * (n + 1) // 2
    for i in range(1, n + 1):
      left_sum = i * (i + 1) // 2
      if left_sum == total_sum - left_sum + i:
        return i
    return -1

# Time  : O(logn)
# Space : O(1)

class Solution:
  def pivotInteger(self, n: int) -> int:
    total_sum = n * (n + 1) // 2
    lo, hi = 1, n

    while lo <= hi:
      mid = lo + (hi - lo) // 2
      left_sum = mid * (mid + 1) // 2 
      right_sum = total_sum - left_sum + mid
      if left_sum < right_sum:
        lo = mid + 1
      elif left_sum > right_sum:
        hi = mid - 1
      else:
        return mid

    return -1