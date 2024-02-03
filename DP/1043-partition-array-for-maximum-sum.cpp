// Time:  O(n*k)
// Space: O(n)

class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& A, int& k) {
    int n = A.size();
    vector<int> memo(n, -1);
    return dfs(0, A, k, n, memo);
  }

  int dfs(int i, vector<int>& A, int& k, int& n, vector<int>& memo) {
    // if (i >= n)
    //   return 0;
    if (memo[i] != -1)
      return memo[i];

    int maxi = -1;
    int res = 0;
    for (int j = i; j < min(i + k, n); ++j) {
      maxi = max(maxi, A[j]);
      res = max(res, maxi * (j - i + 1) + dfs(j+1, A, k, n, memo));
    }
    return memo[i] = res;
  }
};

// Time:  O(n*k)
// Space: O(n)

class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& A, int k) {
    int n = A.size();
    vector<int> dp(n+1);

    for (int i = n-1; i >= 0; --i) {
      int maxi = -1;
      int res = 0;
      for (int j = i; j < min(n, i + k); ++j) {
        maxi = max(maxi, A[j]);
        res = max(res, maxi * (j - i + 1) + dp[j+1]);
      }
      dp[i] = res;
    }

    return dp[0];
  }
};

// Time:  O(n*k)
// Space: O(n)

class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& A, int k) {
    int n = A.size();
    vector<int> dp(n+1);

    for (int i = 1; i <= n; ++i) {
      int maxi = -1;
      int res = 0;
      for (int j = 1; j <= k && i - j >= 0; ++j) {
        maxi = max(maxi, A[i - j]);
        res = max(res, maxi * j + dp[i-j]);
      }
      dp[i] = res;
    }

    return dp[n];
  }
};

// Time:  O(n*k)
// Space: O(n)

class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& A, int k) {
    int n = A.size();
    vector<int> dp(n);
    dp[0] = A[0];
    
    for (int i = 1; i < n; ++i) {
      int curr_max = -1;
      int res = 0;
      for (int j = i; j > max(-1, i-k); --j) {
        curr_max = max(curr_max, A[j]);
        res = max(res, curr_max * (i-j+1) + (j > 0 ? dp[j-1] : 0));
      }
      dp[i] = res;
    }

    return dp[n-1];
  }
};

// Time:  O(n*k)
// Space: O(k)

class Solution:
  def maxSumAfterPartitioning(self, A: List[int], k: int) -> int:
    dp = [0] * k
    dp[0] = A[0]

    for i in range(1, len(A)):
      cur_max = 0
      max_at_i = 0

      for j in range (i, max(-1, i - k), -1):
        cur_max = max(cur_max, A[j])
        window_size = i - j + 1
        cur_sum = cur_max * window_size
        sub_sum = dp[(j - 1) % k] if j > 0 else dp[-1]
        max_at_i = max(max_at_i, cur_sum + sub_sum)

      dp[i % k] = max_at_i

    return dp[(len(A) - 1) % k]