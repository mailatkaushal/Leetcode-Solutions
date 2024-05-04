// Time  : O(n*32)
// Space : O(1)
class Solution {
public:
  int totalHammingDistance(vector<int>& A) {
    // The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
    int n = A.size();
    int ans = 0;
    for (int j = 0; j <= 31; ++j) {
      int ones = 0;
      for (int i = 0; i < n; ++i) {
        ones += (A[i] >> j) & 1;
      }
      ans += ones * (n - ones);
    }
    return ans;
  }
};