// Time  : O(logn)
// Space : O(1)
class Solution {
public:
  int findKthPositive(vector<int>& A, int k) {
    int lo = 0;
    int hi = A.size()-1;
    while (lo < hi) {
      int mid = (lo + hi)>>1;
      if (A[mid]-mid-1 < k) lo = mid+1;
      else hi = mid;
    }
    return k + lo;
  }
};