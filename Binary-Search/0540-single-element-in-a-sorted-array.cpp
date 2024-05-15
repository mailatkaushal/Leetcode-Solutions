// Time  : O(logn)
// Space : O(1)
class Solution {
public:
  int singleNonDuplicate(vector<int>& A) {
    int lo = 0;
    int hi = A.size()-1;
    while (lo < hi) {
      int mid = (lo + hi)>>1;
      if (mid % 2 == 0) {
        if (A[mid] == A[mid+1]) lo = mid+2;
        else hi = mid;
      }
      else {
        if (A[mid-1] == A[mid]) lo = mid+1;
        else hi = mid-1;
      }
    }
    return A[lo];
  }
};