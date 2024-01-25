/*
  Given 2 strings, return length of longest common subsequence
  Ex. text1 = "abcde", text2 = "ace" -> 3, "ace" is LCS
  
                    j
                a   c   e   
            _   _   _   _
          | 0   0   0   0
      a   | 0   1   1   1
      b   | 0   1   1   1
  i   c   | 0   1   2   2   --> visualization of below, DP bottom-up
      d   | 0   1   2   2
      e   | 0   1   2   3

  Time: O(m*n)
  Space: O(m*n)
*/

class Solution {
public:
  int longestCommonSubsequence(string& s, string& t) {
    int m = s.size();
    int n = t.size();

    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s[i-1] == t[j-1])
          dp[i][j] = 1 + dp[i-1][j-1];
        else 
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }

    return dp[m][n];
  }
};

// Time: O(m*n)
// Space: O(n)

class Solution {
public:
  int longestCommonSubsequence(string& s, string& t) {
    int m = s.size();
    int n = s.size();

    vector<int> prev(n+1, 0), curr(n+1, 0);

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s[i-1] == t[j-1]) 
          curr[j] = 1 + prev[j-1];
        else 
          curr[j] = max(prev[j], curr[j-1]);
      }
      prev = curr;
    }

    return prev[n];
  }
};