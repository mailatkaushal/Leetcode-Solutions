/*
  Recursion + Memo
  Time  : O(m*n*n)
  Space : O(m*n*n)
*/

class Solution {
public:
  int m, n;
  vector<int> col_dir = {-1, 0, 1};
  int t[70][70][70];

  int dfs(vector<vector<int>>& grid, int r, int c1, int c2) {
    if (r == m)
      return 0;
    if (t[r][c1][c2] != -1) 
      return t[r][c1][c2];

    int curr_row = grid[r][c1];
    if (c1 != c2) 
      curr_row += grid[r][c2];

    int res = 0;
    for (int& x : col_dir) {
      for (int& y : col_dir) {
        int nc1 = x + c1;
        int nc2 = y + c2;

        if (0 <= nc1 && nc1 < n && 0 <= nc2 && nc2 < n) 
          res = max(res, dfs(grid, r + 1, nc1, nc2));
      }
    }

    return t[r][c1][c2] = curr_row + res;
  }

  int cherryPickup(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    memset(t, -1, sizeof(t));
    return dfs(grid, 0, 0, n-1);
  }
};

/*
  Bottom Up Dp - 3d array
  Time  : O(m*n*n)
  Space : O(m*n*n)
*/

class Solution {
public:
  int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int dp[70][70][70] = {0};
    // dp[r][c1][c2] =  max cherries that can be collected till (row, c1) by robot1 and (row, c2) by robot2

    // for row 0 robot1 is at col 0 & robot2 is at col n-1
    dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];

    for (int r = 1; r < m; ++r) {
      for (int c1 = 0; c1 <= min(r, n-1); ++c1) {
        for (int c2 = max(0, n-1-r); c2 < n; ++c2) {
          // robots can come to current col from either col - 1, col or col + 1 of prev row (row - 1)
          int prev_max = 0;

          for (int nc1 = max(0, c1-1); nc1 <= min(c1+1, n-1); ++nc1) {
            for (int nc2 = max(0, c2-1); nc2 <= min(c2+1, n-1); ++nc2) {
              prev_max = max(prev_max, dp[r - 1][nc1][nc2]);
            }
          }

          dp[r][c1][c2] = prev_max + grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
        }
      }
    }

    int res = 0;

    for (auto& v : dp[m-1]) 
      for (int& n : v) 
        res = max(res, n);

    return res;
  }
};

/*
  Bottom Up Dp - Space Optimised - 2d array
  Time  : O(n*n)
  Space : O(n*n)
*/

class Solution {
public:
  int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> prev(n, vector<int> (n));

    for (int r = 0; r < m; ++r) {
      vector<vector<int>> curr(n, vector<int> (n));
      for (int c1 = 0; c1 <= min(r, n-1); ++c1) {
        for (int c2 = max(0, n-1-r); c2 < n; ++c2) {
          int res = 0;

          for (int nc1 = max(0, c1-1); nc1 <= min(c1+1, n-1); ++nc1) 
            for (int nc2 = max(0, c2-1); nc2 <= min(c2+1, n-1); ++nc2) 
              res = max(res, prev[nc1][nc2]);

          curr[c1][c2] = res + grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
        }
      }
      prev = curr;
    }

    int res = 0;

    for (auto& v : prev) 
      for (int& n : v)
        res = max(res, n);

    return res;
  }
};