// Time  : O(m*n)
// Space : O(m*n)

class Solution {
public:
  int orangesRotting(vector<vector<int>> grid) {
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int m = grid.size();
    int n = grid[0].size();
    int fresh = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) ++fresh;
        if (grid[i][j] == 2) q.push({i, j});
      }
    }
    if (fresh == 0) return 0;
    int time = -1;
    while (!q.empty()) {
      ++time;
      int k = q.size();
      while (k--) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (auto& dir : dirs) {
          int nx = x + dir[0];
          int ny = y + dir[1];
          if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
            grid[nx][ny] = 2;
            q.push({nx, ny});
            --fresh;
          } 
        }
      }
    }
    return fresh == 0 ? time : -1;
  }
};