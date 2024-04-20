// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  int findMaxFish(vector<vector<int>>& grid) {
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          int f = grid[i][j];
          grid[i][j] = 0;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& dir : dirs) {
              int nx = x + dir[0];
              int ny = y + dir[1];
              if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny]) {
                f += grid[nx][ny];
                grid[nx][ny] = 0;
                q.push({nx, ny});
              }
            }
          }
          ans = max(ans, f);
        }
      }
    }
    return ans;
  }
};