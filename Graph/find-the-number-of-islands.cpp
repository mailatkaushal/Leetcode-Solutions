// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  // Function to find the number of islands.
  int numIslands(vector<vector<char>>& grid) {
    int cnt = 0;
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          ++cnt;
          grid[i][j] = '0';
          q.push({i, j});
          while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for (int dx = -1; dx <= 1; ++dx) {
              for (int dy = -1; dy <= 1; ++dy) {
                // if (dx == 0 && dy == 0) continue;
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                  grid[nx][ny] = '0';
                  q.push({nx, ny});
                }
              }
            }
          }
        }
      }
    }
    return cnt;
  }
};