// Time  : O(logn)
// Space : O(1)
class Solution {
public:
  int searchInsert(vector<int>& A, int x) {
    int lo = 0;
    int hi = A.size();
    while (lo < hi) {
      int mid = (lo + hi)>>1;
      if (A[mid] < x) lo = mid+1;
      else hi = mid;
    }
    return lo;
  }
};