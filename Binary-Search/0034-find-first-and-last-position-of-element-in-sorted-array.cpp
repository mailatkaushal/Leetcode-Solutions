// Time  : O(logn)
// Sapce : O(1)
class Solution {
public:
  vector<int> searchRange(vector<int>& A, int x) {
    int n = A.size();
    int lo = 0;
    int hi = n;
    while (lo < hi) {
      int mid = (lo + hi)>>1;
      if (A[mid] < x) lo = mid+1;
      else hi = mid;
    }
    if (lo == n || A[lo] != x) return {-1, -1};
    int first = lo;
    lo = 0;
    hi = n;
    while (lo < hi) {
      int mid = (lo + hi)>>1;
      if (A[mid] <= x) lo = mid+1;
      else hi = mid;
    }
    return {first, lo-1};
  }
};