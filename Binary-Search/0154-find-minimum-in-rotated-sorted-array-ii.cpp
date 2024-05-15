// Time  : O(logn)
// Space : O(1)
class Solution {
public:
  int findMin(vector<int>& A) {
    int lo = 0;
    int hi = A.size()-1;
    while (lo < hi) {
      int mid = (lo + hi)>>1;
      if (A[mid] > A[hi]) lo = mid+1;
      else if (A[mid] < A[hi]) hi = mid;
      else {
        if (A[hi-1] <= A[hi]) hi--;
        else {
          lo = hi;
          break;
        }
      }
    }
    return A[lo];
  }
};