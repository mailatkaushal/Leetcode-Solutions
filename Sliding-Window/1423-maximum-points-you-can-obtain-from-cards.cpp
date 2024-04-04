// Time  : O(2k)
// Space : O(1)

class Solution {
public:
  int maxScore(vector<int>& A, int k) {
    int n = A.size();
    int lsum = 0;
    for (int i = 0; i < k; ++i) lsum += A[i];
    int maxsum = lsum;
    int rsum = 0;
    for (int i = k-1, j = n-1; i >= 0; --i, --j) {
      lsum -= A[i];
      rsum += A[j];
      maxsum = max(maxsum, lsum + rsum);
    }
    return maxsum;
  }
};