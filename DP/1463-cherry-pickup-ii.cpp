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