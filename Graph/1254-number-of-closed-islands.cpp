// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  int closedIsland(vector<vector<int>>& grid) {
   vector<pair<int, int>> dirs = {{-1,0},{1, 0},{0,-1},{0,1}};
    int cnt = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || i == m-1 || j == 0 || j == n-1) {
          if (grid[i][j] == 0) {
            grid[i][j] = 1;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
              auto [x, y] = q.front();
              q.pop();
              for (auto& [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                  grid[nx][ny] = 1;
                  q.push({nx, ny});
                }
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          ++cnt;
          grid[i][j] = 1;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& [dx, dy] : dirs) {
              int nx = x + dx;
              int ny = y + dy;
              if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                grid[nx][ny] = 1;
                q.push({nx, ny});
              }
            }
          }
        }
      }
    }
    return cnt;
  }
};