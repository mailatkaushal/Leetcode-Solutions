// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ma = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          int a = 1;
          grid[i][j] = -1;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& dir : dirs) {
              int nx = x + dir[0];
              int ny = y + dir[1];
              if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                ++a;
                grid[nx][ny] = -1;
                q.push({nx, ny});
              }
            }
          }
          ma = max(ma, a);
        }
      }
    }
    return ma;
  }
};