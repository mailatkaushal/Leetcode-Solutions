// Time  : O(logn)
// Space : O(1)
class Solution {
public:
  int findPeakElement(vector<int>& A) {
    int lo = 0;
    int hi = A.size()-1;
    while (lo < hi) {
      int mid = (lo + hi)>>1;
      if (A[mid] < A[mid+1]) lo = mid+1;
      else hi = mid;
    }
    return lo;
  }
};