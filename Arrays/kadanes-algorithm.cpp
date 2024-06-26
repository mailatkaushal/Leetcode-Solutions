class Solution {
public:
  int maxSubArray(vector<int>& A) {
    int n = A.size();
    int ans = INT_MIN;
    int x = 0;
    for (int i=0; i<n; ++i) {
      x += A[i];
      ans = max(ans, x);
      if (x < 0) x = 0;
    }
    return ans;
  }
};