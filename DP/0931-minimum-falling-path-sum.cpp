// Time: O(n^2)
// Space: O(n^2)

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int> (n));
    dp[0] = A[0];

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) 
        dp[i][j] = A[i][j] + min({
          dp[i-1][max(0, j-1)],
          dp[i-1][j],
          dp[i-1][min(n-1, j+1)]
        });
    }

    return *min_element(dp[n-1].begin(), dp[n-1].end());
  }
};

// Time: O(n^2)
// Space: O(n)

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& A) {
    int n = A.size();
    vector<int> prev(n);
    for (int i = 0; i < n; ++i) 
      prev[i] = A[0][i];

    for (int i = 1; i < n; ++i) {
      vector<int> curr(n);
      for (int j = 0; j < n; ++j) 
        curr[j] = A[i][j] + min({prev[max(0, j-1)], prev[j], prev[min(n-1, j+1)]});
      prev = curr;
    }

    return *min_element(prev.begin(), prev.end());
  }
};

// Time: O(n^2)
// Space: O(1)

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& A) {
    int n = A.size();

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) 
        A[i][j] += min({
          A[i-1][max(0, j-1)],
          A[i-1][j],
          A[i-1][min(n-1, j+1)]
        });
    }

    return *min_element(A[n-1].begin(), A[n-1].end());
  }
};

// a-2