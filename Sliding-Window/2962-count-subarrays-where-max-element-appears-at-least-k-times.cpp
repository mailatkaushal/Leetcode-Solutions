// Time  : O(n)
// Space : O(1)

class Solution {
public:
  long long countSubarrays(vector<int>& A, int k) {
    int n = A.size();
    long long cnt = 0;
    int ma = *max_element(A.begin(), A.end());
    int cntma = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      if (A[r] == ma)
        ++cntma;
      while (cntma == k) {
        cnt += n - r;
        if (A[l] == ma)
          --cntma;
        ++l;
      }
    }
    return cnt;
  }
};