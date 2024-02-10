/*
  Recursion + Memo
  Time  : O(2n)
  Space : O(n)
*/

typedef long long ll;
class Solution {
public:
  long long maxAlternatingSum(vector<int>& A) {
    int n = A.size();
    vector<vector<ll>> memo(n, vector<ll> (2, -1));
    return f(A, 0, true, memo);
  }

  ll f(vector<int>& A, int i, bool isEven, vector<vector<ll>>& memo) {
    if (i == A.size()) 
      return 0;
    if (memo[i][isEven] != -1)
      return memo[i][isEven];

    ll take = ((isEven) ? A[i] : -A[i]);
    take += f(A, i+1, !isEven, memo);

    ll skip = f(A, i+1, isEven, memo);

    return memo[i][isEven] = max(take, skip);
  }
};

/* 
  Bottom Up DP
  Time  : O(n)
  Space : O(n)
*/

class Solution {
public:
  long long maxAlternatingSum(vector<int>& A) {
    int n = A.size();
    vector<vector<long>> dp(n, vector<long> (2));  // even -> 0, odd -> 1

    dp[0][0] = max(-A[0], 0);
    dp[0][1] = max(A[0], 0);

    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i-1][1] - A[i], dp[i-1][0]);
      dp[i][1] = max(dp[i-1][0] + A[i], dp[i-1][1]);
    }

    return max(dp[n-1][0], dp[n-1][1]);
  }
};