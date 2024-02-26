// Time:  O(n)
// Space: O(n)

class Solution:
  def numDecodings(self, s: str) -> int:
    n = len(s)
    mem = [-1] * (n + 1)

    def dfs(i: int):
      if i == n:
        return 1
      if mem[i] != -1:
        return mem[i]
      if s[i] == '0':
        return 0
 
      res = dfs(i+1)
      if i < n-1 and (s[i] == '1' or (s[i] == '2' and s[i+1] <= '6')):
        res += dfs(i+2)
      mem[i] = res
      return res

    return dfs(0)

// Time:  O(n)
// Space: O(n)

class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[n] = 1;

    for (int i = n-1; i >= 0; --i) {
      if (s[i] == '0')
        continue;
      dp[i] = dp[i+1];
      if (i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
        dp[i] += dp[i+2];
    }
    
    return dp[0];
  }
};

// Time:  O(n)
// Space: O(n)

class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
      if (s[i-1] != '0')
        dp[i] = dp[i-1];
      if (i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')))
        dp[i] += dp[i-2];
    }
    
    return dp[n];
  }
};