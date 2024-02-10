/*
  Recursion - TLE
  Time  : O(2^n)
  Space : O(n)
*/

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& A) {
    sort(A.begin(), A.end());
    vector<int> res, tmp;
    lds(-1, 0, A, res, tmp);
    return res;
  }

  void lds(int prev, int curr, vector<int>& A, vector<int>& res, vector<int>& tmp) {
    if (curr >= A.size()) {
      if (tmp.size() > res.size())
        res = tmp;
      return;
    }

    if (prev == -1 || A[curr] % prev == 0) {
      tmp.push_back(A[curr]);
      lds(A[curr], curr + 1, A, res, tmp);
      tmp.pop_back();
    }

    lds(prev, curr + 1, A, res, tmp);
  }
};

/*
  Bottom Up DP
  Time  : O(n^2)
  Space : O(n)
*/

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& A) {
    sort(A.begin(), A.end());

    int n = A.size();
    vector<int> dp(n, 1);
    vector<int> pre(n, -1);  // the index of the previous element in the same subset
    int maxLen = 0;
    int lastIdx = -1; 

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (A[i] % A[j] == 0) {
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            pre[i] = j;
          }
        }
      }
      if (dp[i] > maxLen) {
        maxLen = dp[i];
        lastIdx = i;
      }
    }

    vector<int> res(maxLen);
    for (int i = maxLen-1; i >= 0; --i) {
      res[i] = A[lastIdx];
      lastIdx = pre[lastIdx];
    }

    return res;
  }
};