// Time:  O(m*n*maxMove)
// Space: O(m*n*maxMove)

class Solution {
public:
  int M, N;
  int MOD = 1e9+7;
  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<vector<int>>> memo;

  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    M = m;
    N = n;
    memo = vector<vector<vector<int>>> (M, vector<vector<int>> (N, vector<int> (maxMove+1, -1)));
    return dfs(startRow, startColumn, maxMove);
  }

  int dfs(int i, int j, int maxMove) {
    if (i < 0 || i > M-1 || j < 0 || j > N-1)
      return 1;

    if (maxMove == 0) 
      return 0;

    if (memo[i][j][maxMove] != -1)
      return memo[i][j][maxMove];

    int res = 0;

    for (auto& dir: dirs) {
      int r = i + dir[0];
      int c = j + dir[1];
      res = (res + dfs(r, c, maxMove-1)) % MOD;
    }
    
    return memo[i][j][maxMove] = res;
  }
};

// Time:  O(m*n*maxMove)
// Space: O(m*n*maxMove)

class Solution {
public:
  int MOD = 1e9+7;
  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    int dp[m][n][maxMove+1];
    memset(dp, 0, sizeof(dp));

    for (int k = 1; k <= maxMove; ++k) {
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          for (auto& dir: dirs) {
            int r = i + dir[0];
            int c = j + dir[1];
            if (r < 0 || r > m-1 || c < 0 || c > n-1)
              dp[i][j][k] = (dp[i][j][k] + 1) % MOD;
            else 
              dp[i][j][k] = (dp[i][j][k] + dp[r][c][k-1]) % MOD;
          }
        }
      }
    }

    return dp[startRow][startColumn][maxMove];
  }
};

// Time:  O(m*n*maxMove)
// Space: O(m*n)

class Solution {
public:
  int MOD = 1e9+7;
  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<int>> prev(m, vector<int> (n));
    prev[startRow][startColumn] = 1;
    int res = 0;

    for (int k = 1; k <= maxMove; ++k) {
      vector<vector<int>> curr(m, vector<int> (n));
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          for (auto& dir: dirs) {
            int r = i + dir[0];
            int c = j + dir[1];
            if (r < 0 || r > m-1 || c < 0 || c > n-1)
              res = (res + prev[i][j]) % MOD;
            else 
              curr[r][c] = (curr[r][c] + prev[i][j]) % MOD;
          }
        }
      }
      prev = curr;
    }

    return res;
  }
};