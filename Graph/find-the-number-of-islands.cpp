// Time  : O(n^2)
// Space : O(n^2)

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    vector<vector<int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int cnt = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool> (n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1' && !vis[i][j]) {
          ++cnt;
          vis[i][j] = 1;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (auto& dir : dirs) {
              int nx = x + dir[0];
              int ny = y + dir[1];
              if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1' && !vis[nx][ny]) {
                vis[nx][ny] = 1;
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