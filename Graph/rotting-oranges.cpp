// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int m = grid.size();
    int n = grid[0].size();
    int fresh = 0;
    queue<pair<int,int>> q;
    for (int i=0; i<m; ++i) {
      for (int j=0; j<n; ++j) {
        if (grid[i][j] == 1) ++fresh;
        else if (grid[i][j] == 2) q.push({i,j});
      }
    }
    if (fresh == 0) return 0;
    int ans = -1;
    while (!q.empty()) {
      int z = q.size();
      while (z--) {
        auto [x, y] = q.front(); q.pop();
        for (auto& [dx, dy] : dirs) {
          int nx = x + dx;
          int ny = y + dy;
          if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == 1) {
            grid[nx][ny] = 2;
            q.push({nx, ny});
            --fresh;
          }
        }
      }
      ++ans;
    }
    return fresh == 0 ? ans : -1;
  }
};