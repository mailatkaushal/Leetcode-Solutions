// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int maxSubarrayLength(vector<int>& A, int k) {
    int n = A.size();
    int ma = 0;
    unordered_map<int, int> ump;
    for (int l = 0, r = 0; r < n; ++r) {
      ++ump[A[r]];
      while (ump[A[r]] > k) {
        --ump[A[l]];
        ++l;
      }
      ma = max(ma, r - l + 1);
    }
    return ma;
  }
};