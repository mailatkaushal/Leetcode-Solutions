// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int m = grid1.size();
    int n = grid1[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid1[i][j] == 0 && grid2[i][j] == 1) {
          grid2[i][j] = 0;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& [dx, dy] : dirs) {
              int nx = x + dx;
              int ny = y + dy;
              if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid2[nx][ny] == 1) {
                grid2[nx][ny] = 0;
                q.push({nx, ny});
              }
            }
          }
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid2[i][j] == 1) {
          ++cnt;
          grid2[i][j] = 0;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& [dx, dy] : dirs) {
              int nx = x + dx;
              int ny = y + dy;
              if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid2[nx][ny] == 1) {
                grid2[nx][ny] = 0;
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