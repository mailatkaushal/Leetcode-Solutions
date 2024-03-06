# Time  : O(m*n)
# Space : O(1)

class Solution:
  def islandPerimeter(self, grid: List[List[int]]) -> int:
    m, n = len(grid), len(grid[0])

    def dfs(i, j):
      if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
        return 1
      if grid[i][j] == -1:
        return 0

      grid[i][j] = -1

      perimeter = dfs(i + 1, j)
      perimeter += dfs(i - 1, j)
      perimeter += dfs(i, j + 1)
      perimeter += dfs(i, j - 1)
      return perimeter

    for i in range(m):
      for j in range(n):
        if grid[i][j] == 1:
          return dfs(i, j)
        
# Time  : O(m*n)
# Space : O(1)
        
class Solution:
  def islandPerimeter(self, grid: List[List[int]]) -> int:
    m, n = len(grid), len(grid[0])
    perimeter = 0
    
    for i in range(m):
      for j in range(n):
        if grid[i][j] == 0:
          continue
        if i+1 >= m or grid[i+1][j] == 0:
          perimeter += 1
        if i-1 < 0 or grid[i-1][j] == 0:
          perimeter += 1
        if j+1 >= n or grid[i][j+1] == 0:
          perimeter += 1
        if j-1 < 0 or grid[i][j-1] == 0:
          perimeter += 1

    return perimeter
  
# Time  : O(m*n)
# Space : O(1)
  
class Solution:
  def islandPerimeter(self, grid: List[List[int]]) -> int:
    m, n = len(grid), len(grid[0])
    perimeter = 0
    
    for i in range(m):
      for j in range(n):
        # If there is a land block increment perimeter by 4
        if grid[i][j] == 1:
          perimeter += 4
          # check top neighbor
          if i > 0 and grid[i-1][j] == 1:
            perimeter -= 2
          # check left neighbor
          if j > 0 and grid[i][j-1] == 1:
            perimeter -= 2 

    return perimeter