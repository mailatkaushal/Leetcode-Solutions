// Time  : O(n^2)
// Space : O(n)

class Solution:
  def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
    n = len(grid)
    col_max = [0] * n  # top-bottom
    row_max = [0] * n  # left-right

    # finding the skyline
    for i in range(n):
      for j in range(n):
        row_max[i] = max(row_max[i], grid[i][j])
        col_max[j] = max(col_max[j], grid[i][j])

    max_inc = 0

    # build the increased skyline
    for i in range(n):
      for j in range(n):
        max_inc += min(row_max[i], col_max[j]) - grid[i][j]

    return max_inc