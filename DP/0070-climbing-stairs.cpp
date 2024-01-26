// Time: O(n)
// Space: O(n)

class Solution {
public:
  int climbStairs(int n) {
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) 
      dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
  }
};

// Time: O(n)
// Space: O(1)

class Solution {
public:
  int climbStairs(int n) {
    int a = 1, b = 1;

    for (int i = 2; i <= n; ++i) {
      int tmp = a + b;
      a = b;
      b = tmp;
    }

    return b;
  }
};