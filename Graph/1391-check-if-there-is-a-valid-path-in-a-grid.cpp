// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  bool hasValidPath(vector<vector<int>>& grid) {
    vector<vector<pair<int, int>>> dirs = {
      {},
      {{0,-1},{0,1}},
      {{-1,0},{1,0}},
      {{0,-1},{1,0}},
      {{1,0},{0,1}},
      {{0,-1},{-1,0}},
      {{-1,0},{0,1}}
    };
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    q.push({grid[0][0], {0, 0}});
    grid[0][0] = 0;
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int s = p.first;
      int x = p.second.first;
      int y = p.second.second;
      if (x == m-1 && y == n-1) return true;
      for (auto& [dx, dy] : dirs[s]) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || nx == m || ny < 0 || ny == n || grid[nx][ny] == 0) continue;
        for (auto& [dx1, dy1] : dirs[grid[nx][ny]]) {
          if (nx + dx1 == x && ny + dy1 == y) {
            q.push({grid[nx][ny], {nx, ny}});
            grid[nx][ny] = 0;
          }
        }
      }
    }
    return false;
  }
};