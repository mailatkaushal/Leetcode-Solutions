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