// Time:  O(n)
// Space: O(n)

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> dp(n);
    dp[0] = 1;
    
    int i2 = 0, i3 = 0, i5 = 0;

    for (int i = 1; i < n; ++i) {
      int i2_ugly = dp[i2] * 2;
      int i3_ugly = dp[i3] * 3;
      int i5_ugly = dp[i5] * 5;

      dp[i] = min({i2_ugly, i3_ugly, i5_ugly});

      if (dp[i] == i2_ugly)
        ++i2;
      if (dp[i] == i3_ugly)
        ++i3;
      if (dp[i] == i5_ugly)
        ++i5;
    }

    return dp[n-1];
  }
};