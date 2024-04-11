// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  int m, n;
  vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
  void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
    vis[x][y] = 1;
    for (auto& dir : dirs) {
      int nx = x + dir[0];
      int ny = y + dir[1];
      if (nx >= 0 && nx <= m-1 && ny >= 0 && ny <= n-1 && !vis[nx][ny] && grid[nx][ny] == 1) 
        dfs(nx, ny, grid, vis);
    }
  }
  int numEnclaves(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool> (n));
    for (int i = 0; i < m; ++i) {
      if (!vis[i][0] && grid[i][0] == 1)
        dfs(i, 0, grid, vis);
      if (!vis[i][n-1] && grid[i][n-1] == 1)
        dfs(i, n-1, grid, vis);
    }
    for (int j = 0; j < n; ++j) {
      if (!vis[0][j] && grid[0][j] == 1)
        dfs(0, j, grid, vis);
      if (!vis[m-1][j] && grid[m-1][j] == 1)
        dfs(m-1, j, grid, vis);
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!vis[i][j] && grid[i][j] == 1) ++cnt;
      }
    }
    return cnt;
  }
};

// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
  int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool> (n));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || i == m-1 || j == 0 || j == n-1) {
          if (grid[i][j] == 1) {
            vis[i][j] = 1;
            q.push({i, j});
          }
        }
      }
    }
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int x = p.first;
      int y = p.second;
      for (auto& dir : dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (nx >= 0 && nx <= m-1 && ny >= 0 && ny <= n-1 && !vis[nx][ny] && grid[nx][ny] == 1) {
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!vis[i][j] && grid[i][j] == 1) ++cnt;
      }
    }
    return cnt;
  }
};