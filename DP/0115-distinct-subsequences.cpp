/*
  Recursion + Memo
  Time  : O(m*n)
  Space : O(m*n)
*/

class Solution:
  def numDistinct(self, s: str, t: str) -> int:
    m = len(s)
    n = len(t)
    memo = [[-1] * (n) for _ in range (m)]

    def dfs(i, j):
      if j == n:
        return 1
      if i == m:
        return 0
      if memo[i][j] != -1:
        return memo[i][j]

      if (s[i] == t[j]):
        memo[i][j] = dfs(i + 1, j + 1) + dfs(i + 1, j)
      else:
        memo[i][j] = dfs(i + 1, j)
        
      return memo[i][j]
      
    return dfs(0, 0)

/*
  Bottom Up Dp
  Ex s = "rabbbit", t = "rabbit" -> 3

                j
            r   a   b   b   i   t   
            _   _   _   _   _   _
      r   | 3   3   3   3   1   1   1
      a   | 0   3   3   3   1   1   1
  i   b   | 0   0   3   3   1   1   1
      b   | 0   0   1   2   1   1   1    --> visualization DP bottom-up
      b   | 0   0   0   1   1   1   1   
      i   | 0   0   0   0   1   1   1
      t   | 0   0   0   0   0   1   1
          | 0   0   0   0   0   0   1

  Time  : O(m*n)
  Space : O(m*n)
*/

class Solution:
  def numDistinct(self, s: str, t: str) -> int:
    m = len(s)
    n = len(t)

    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m + 1):
      dp[i][n] = 1

    for i in range(m - 1, -1, -1):
      for j in range(n - 1, -1, -1):
        if (s[i] == t[j]):
          dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j]
          continue
        dp[i][j] = dp[i + 1][j]
    
    return dp[0][0]

/*
  Bottom Up Dp - Space optimised
  Time  : O(m*n)
  Space : O(n)
*/

class Solution:
  def numDistinct(self, s: str, t: str) -> int:
    m = len(s)
    n = len(t)

    prev = [0] * (n+1)
    prev[n] = 1

    for i in range(m - 1, -1, -1):
      curr = [0] * (n+1)
      curr[n] = 1
      for j in range(n - 1, -1, -1):
        if (s[i] == t[j]):
          curr[j] = prev[j + 1] + prev[j]
          continue
        curr[j] = prev[j]
      prev = curr
    
    return prev[0]

/*
  Bottom Up Dp - Single 1d array
  Time  : O(m*n)
  Space : O(n)
*/

class Solution:
  def numDistinct(self, s: str, t: str) -> int:
    m = len(s)
    n = len(t)

    dp = [0] * (n+1)
    dp[n] = 1

    for i in range(m - 1, -1, -1):
      for j in range(n):
        if (s[i] == t[j]):
          dp[j] += dp[j + 1]
    
    return dp[0]