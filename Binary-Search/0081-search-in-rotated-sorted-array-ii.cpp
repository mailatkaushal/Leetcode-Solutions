// Time  : O(logn) -> O(n)
// Space : O(1)
class Solution {
public:
  bool search(vector<int>& A, int x) {
    int lo = 0;
    int hi = A.size()-1;
    while (lo <= hi) {
      int mid = (lo + hi)>>1;
      if (A[mid] == x) return 1; 
      // fail to estimate which side is sorted 
      if (A[lo] == A[mid] && A[mid] == A[hi]) {
        ++lo;
        --hi;
      }
      else if (A[lo] <= A[mid]) {
        if (A[lo] <= x && x < A[mid]) hi = mid-1;
        else lo = mid+1;
      }
      else {
        if (A[mid] < x && x <= A[hi]) lo = mid+1;
        else hi = mid-1;
      }
    }
    return 0;
  }
};