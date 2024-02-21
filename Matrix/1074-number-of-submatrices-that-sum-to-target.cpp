// Time:  O(n^2 * m)
// Space: O(m)

class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& M, int target) {
    int m = M.size();
    int n = M[0].size();
    int res = 0;

    for (vector<int>& row: M) {
      for (int j = 1; j < n; ++j) 
        row[j] += row[j-1];
    }

    for (int sy = 0; sy < n; ++sy) {
      for (int j = sy; j < n; ++j) {
        unordered_map<int, int> ump;
        ump[0] = 1;
        int sum = 0;

        for (int i = 0; i < m; ++i) {
          sum += M[i][j] - (sy > 0 ? M[i][sy-1] : 0);
          if (ump.find(sum - target) != ump.end())
            res += ump[sum - target];
          ump[sum]++;
        }
      }
    }

    return res;
  }
};

// Time:  O(n^2 * m^2)
// Space: O(m)

class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& M, int target) {
    int m = M.size();
    int n = M[0].size();
    int res = 0;

    vector<vector<int>> dp(m+1, vector<int> (n+1));

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = M[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
      }
    }
    
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= i; ++k) {
          for (int l = 1; l <= j; ++l) {
            if (target == dp[i][j] - dp[k-1][j] - dp[i][l-1] + dp[k-1][l-1])
              ++res;
          }
        }
      }
    }

    return res;
  }
};