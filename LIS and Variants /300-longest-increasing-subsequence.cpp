/*
  Recursion + Memo
  Time  : O(n^2)
  Space : O(n^2)
*/

class Solution {
public:
  vector<vector<int>> memo;

  int lengthOfLIS(vector<int>& A) {
    int n = A.size();
    memo = vector<vector<int>> (n, vector<int> (n, -1));  // prev : 0 -> n-1 & curr : 0 -> n-1
    return lis(A, -1, 0);
  }

  int lis(vector<int>& A, int prev, int curr) {
    if (curr == A.size())
      return 0;
    if (prev != -1 && memo[prev][curr] != -1)
      return memo[prev][curr];
    
    int taken = 0;
    if (prev == -1 || A[prev] < A[curr])
      taken = 1 + lis(A, curr, curr + 1);
    int notTaken = lis(A, prev, curr + 1);

    if (prev != -1)
      return memo[prev][curr] = max(taken, notTaken);
      
    return max(taken, notTaken);
  }
};

/*
  Bottom Up DP
  Time  : O(n^2)
  Space : O(n^2)
*/

class Solution {
public:
  int lengthOfLIS(vector<int>& A) {
    int n = A.size();

    vector<int> dp(n, 1);
    int res = 1;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (A[j] < A[i])
          dp[i] = max(dp[i], 1 + dp[j]);
      }
      res = max(res, dp[i]);
    }

    return res;
  }
};

/*
  Bottom Up DP - 2nd way
  Time  : O(n^2)
  Space : O(n^2)
*/

class Solution:
  def lengthOfLIS(self, A: List[int]) -> int:
    n = len(A)
    dp = [1] * n
    res = 1

    for i in range(n - 1, -1, -1):
      for j in range(i + 1, n):
        if A[i] < A[j]:
          dp[i] = max(dp[i], 1 + dp[j])
      res = max(res, dp[i])

    return res