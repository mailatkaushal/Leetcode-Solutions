// Time  : O(n*26)
// Space : O(26)
class Solution {
public:
  int longestIdealString(string s, int k) {
    int n = s.size();
    vector<int> dp(26);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int x = s[i] - 'a';
      int l = max(0, x-k);
      int r = min(25, x+k);
      for (int j = l; j <= r; ++j) {
        dp[x] = max(dp[x], dp[j]);
      }
      ans = max(ans, ++dp[x]);
    }
    return ans;
  }
};