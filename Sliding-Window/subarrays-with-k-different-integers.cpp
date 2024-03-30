// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int atMost(vector<int>& A, int k) {
    int n = A.size();
    unordered_map<int, int> ump;
    int cnt = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      ++ump[A[r]];
      while (ump.size() > k) {
        --ump[A[l]];
        if (ump[A[l]] == 0) ump.erase(A[l]);
        ++l;
      }
      cnt += r-l+1;
    }
    return cnt;
  }

  int subarraysWithKDistinct(vector<int>& A, int k) {
    return atMost(A, k) - atMost(A, k-1);
  }
};