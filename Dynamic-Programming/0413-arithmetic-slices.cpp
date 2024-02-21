// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    vector<int> dp(n);
    int res = 0;

    for (int i = 2; i < n; ++i) {
      if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
        dp[i] = 1 + dp[i-1];
        res += dp[i];
      }
    }

    return res;
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    int prev = 0;
    int res = 0;

    for (int i = 2; i < n; ++i) {
      if (A[i] - A[i-1] == A[i-1] - A[i-2]) 
        res += ++prev;
      else 
        prev = 0;
    }
    
    return res;
  }
};