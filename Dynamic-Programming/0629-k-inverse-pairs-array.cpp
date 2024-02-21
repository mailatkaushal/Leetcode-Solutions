// Time:  O(n*k*n)
// Space: O(n*k)

class Solution {
public:
  int M = 1e9+7;
  vector<vector<int>> memo;

  int kInversePairs(int n, int k) {
    memo = vector<vector<int>> (n+1, vector<int> (k+1, -1));
    return dfs(n, k);
  }

  int dfs(int n, int k) {
    if (n == 0)
      return 0;
    if (k == 0)
      return 1;
    if (memo[n][k] != -1) 
      return memo[n][k];

    int res = 0;
    for (int i = 0; i <= min(k, n-1); ++i) 
      res = (res + dfs(n-1, k-i) % MOD) % MOD;

    return memo[n][k] = res;
  }
};

/*
  Ex. n = 5, k = 5 -> 22

                      j
            0   1   2   3   4   5
            _   _   _   _   _   _
      0   | 1   0   0   0   0   0
      1   | 1   0   0   0   0   0
      2   | 1   1   0   0   0   0
  i   3   | 1   2   2   1   0   0   --> visualization DP bottom-up
      4   | 1   3   5   6   5   3
      5   | 1   4   8   15  20  22

  Time:  O(n*k*n)
  Space: O(n*k)
*/

class Solution {
public:
  int kInversePairs(int n, int k) {
    int M = 1e9+7;
    vector<vector<int>> dp (n+1, vector<int> (k+1));

    for (int i = 0; i <= n; ++i)
      dp[i][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
        for (int k = 0; k <= min(j, i-1); ++k) {
          dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % M;
        }
      }
    }

    return dp[n][k];
  }
};

// Time:  O(n*k)
// Space: O(k)

class Solution {
public:
  int kInversePairs(int n, int k) {
    int M = 1e9+7;
    vector<int> prev(k+1);
    prev[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
      vector<int> curr(k+1);
      curr[0] = 1;
      long long cumSum = 1;
      for (int j = 1; j <= k; ++j) {
        cumSum += prev[j];
        if (j >= i)
          cumSum -= prev[j-i];
        curr[j] = cumSum % M;
      }
      prev = curr;
    }

    return prev[k];
  }
};