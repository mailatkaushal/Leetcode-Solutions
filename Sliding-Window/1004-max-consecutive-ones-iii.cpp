// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int longestOnes(vector<int>& A, int k) {
    int ans = 0;
    int zeroes = 0;
    for (int i = 0, j = 0; j < A.size(); ++j) {
      zeroes += A[j] == 0 ? 1 : 0;
      if (zeroes > k) {
        zeroes -= A[i] == 0 ? 1 : 0;
        ++i;
      }
      ans = max(ans, j-i+1);
    }
    return ans;
  }
};