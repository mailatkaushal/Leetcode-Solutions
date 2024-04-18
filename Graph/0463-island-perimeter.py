# Time  : O(m*n)
# Space : O(m*n)
class Solution {
public:
  vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
  int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          int pm = 0;
          grid[i][j] = -1;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& dir : dirs) {
              int nx = x + dir[0];
              int ny = y + dir[1];
              if (nx < 0 || nx == m || ny < 0 || ny == n || grid[nx][ny] == 0) ++pm;
              else if (grid[nx][ny] == -1) continue;
              else {
                grid[nx][ny] = -1;
                q.push({nx, ny});
              }
            }
          }
          return pm;
        }
      }
    }
    return 0;
  }
};

# Iterative
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