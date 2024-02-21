// Time:  O(m*n)
// Space: O(m*n)

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int> (n, 0));

    for (int i = 0; i < m; ++i) {
      if (obstacleGrid[i][0] == 0)
        dp[i][0] = 1;
      else 
        break;
    }

    for (int i = 0; i < n; ++i) {
      if (obstacleGrid[0][i] == 0)
        dp[0][i] = 1;
      else 
        break;
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j] == 0) 
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }

    return dp[m-1][n-1];
  }
};

// Time:  O(m*n)
// Space: O(n)

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> prev(n, 0);

    for (int i = 0; i < n; ++i) {
      if (obstacleGrid[0][i] == 0)
        prev[i] = 1;
      else 
        break;
    }

    for (int i = 1; i < m; ++i) {
      vector<int> curr(n, 0);
      for (int j = 0; j < n; ++j) {
        if (obstacleGrid[i][j] == 1) 
          curr[j] = 0;
        else if (j > 0) 
          curr[j] = prev[j] + curr[j-1];
        else 
          curr[j] = prev[j];
      }
      prev = curr;
    }

    return prev[n-1];
  }
};

// Time:  O(m*n)
// Space: O(n)

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (obstacleGrid[i][j] == 1)
          dp[j] = 0;
        else if (j > 0) 
          dp[j] += dp[j-1];
      }
    }

    return dp[n-1];
  }
};