// Time:  O(n * n^1/2)
// Space: O(n)

class Solution {
public:
  int numSquares(int n) {
    vector<int> memo(n+1, -1);
    return f(n, memo);
  }

  int f(int n, vector<int>& memo) {
    if (n == 0)
      return 0;
    if (memo[n] != -1)
      return memo[n];

    int minCnt = INT_MAX;
    for (int i = 1; i*i <= n; ++i) 
      minCnt = min(minCnt, 1 + f(n-i*i, memo));
      
    return memo[n] = minCnt;
  }
};

// Time:  O(n * n^1/2)
// Space: O(n)

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n+1, n);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j*j <= i; ++j) 
        dp[i] = min(dp[i], 1 + dp[i-j*j]);
    }

    return dp[n];
  }
};