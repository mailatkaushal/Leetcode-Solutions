// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
  int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          q.push({i, j});
        }
      }
    }
    if (q.empty() || q.size() == n*n) return -1;
    int dist = -1;
    while (!q.empty()) {
      ++dist;
      int k = q.size();
      while (k--) {
        auto [x, y] = q.front();
        q.pop();
        for (auto& dir : dirs) {
          int nx = x + dir[0];
          int ny = y + dir[1];
          if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
            grid[nx][ny] = 1;
            q.push({nx, ny});
          }
        }
      }
    }
    return dist;
  }
};