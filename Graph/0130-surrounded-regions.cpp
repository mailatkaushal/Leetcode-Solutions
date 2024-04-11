// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  int m, n;
  vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
  void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& vis) {
    vis[x][y] = 1;
    for (auto& dir : dirs) {
      int nx = x + dir[0];
      int ny = y + dir[1];
      if (nx >= 0 && nx <= m-1 && ny >= 0 && ny <= n-1 && !vis[nx][ny] && board[nx][ny] == 'O') 
        dfs(nx, ny, board, vis);
    }
  }
  void solve(vector<vector<char>>& board) {
    m = board.size();
    n = board[0].size();
    vector<vector<bool>> vis(m, vector<bool> (n));
    for (int i = 0; i < m; ++i) {
      if (!vis[i][0] && board[i][0] == 'O')
        dfs(i, 0, board, vis);
      if (!vis[i][n-1] && board[i][n-1] == 'O')
        dfs(i, n-1, board, vis);
    }
    for (int j = 0; j < n; ++j) {
      if (!vis[0][j] && board[0][j] == 'O')
        dfs(0, j, board, vis);
      if (!vis[m-1][j] && board[m-1][j] == 'O')
        dfs(m-1, j, board, vis);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
      }
    }
  }
};

// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
  void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> vis(m, vector<bool> (n));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || i == m-1 || j == 0 || j == n-1) {
          if (board[i][j] == 'O') {
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
        if (nx >= 0 && nx <= m-1 && ny >= 0 && ny <= n-1 && !vis[nx][ny] && board[nx][ny] == 'O') {
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
      }
    }
  }
};