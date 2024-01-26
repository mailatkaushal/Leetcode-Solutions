// Time: O(3^m*n)
// Space: O(m*n)

class Solution {
public:
  int m, n;
  int res = 0;
  int empty;

  int uniquePathsIII(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    empty = 1;
    int sx, sy;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0)
          ++empty;
        else if (grid[i][j] == 1) 
          sx = i, sy = j;
      }
    }

    dfs(grid, 0, sx, sy);

    return res;
  }

  void dfs(vector<vector<int>>& grid, int curr, int i, int j) {
    if (i < 0 || i > m-1 || j < 0 || j > n-1 || grid[i][j] == -1)
      return;

    if (grid[i][j] == 2) {
      if (empty == curr) 
        ++res;
      return;
    }

    grid[i][j] = -1;
    
    dfs(grid, curr+1, i+1, j);
    dfs(grid, curr+1, i-1, j);
    dfs(grid, curr+1, i, j+1);
    dfs(grid, curr+1, i, j-1);

    grid[i][j] = 0;
  }
};