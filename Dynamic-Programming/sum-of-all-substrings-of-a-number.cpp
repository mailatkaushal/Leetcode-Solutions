// Time  : O(n)
// Space : O(n)

class Solution {
  public:
  int mod = 1e9+7;
  // Function to find sum of all possible substrings of the given string.
  long long sumSubstrings(string s) {
    int n = s.size();
    vector<long long> dp(n);
    dp[0] = s[0]-'0';
    long long ans = dp[0];
    for (int i = 1; i < n; ++i) {
      dp[i] = ((dp[i-1]*10)%mod + ((s[i]-'0')*(i+1))%mod)%mod;
      ans = (ans + dp[i])%mod;
    }
    return ans;
  }
};