// Time: o(m*n)
// Space: O(m*n)

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, 1));

    for (int i = 1; i < m; ++i) 
      for (int j = 1; j < n; ++j) 
        dp[i][j] = dp[i-1][j] + dp[i][j-1];

    return dp[m-1][n-1];
  }
};

// Time: o(m*n)
// Space: O(n)

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<int> prev(n, 1);

    for (int i = 1; i < m; ++i) {
      vector<int> curr(n, 1);
      for (int j = 1; j < n; ++j) 
        curr[j] = prev[j] + curr[j-1];
      prev = curr;
    }

    return prev[n-1];
  }
};

// Time: o(m*n)
// Space: O(n)

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<int> row(n, 1);

    for (int i = 1; i < m; ++i) {
      for(int j = 1; j < n; ++j)
        row[j] += row[j-1];
    }

    return row[n-1];
  }
};