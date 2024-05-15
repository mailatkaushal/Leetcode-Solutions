// Time  : O(logn)
// Space : O(1)
class Solution {
public:
  int findInMountainArray(int x, MountainArray& A) {
    int n = A.length();
    int lo = 0;
    int hi = n-1;
    while (lo < hi) {
      int mid = (lo + hi)>>1;
      if (A.get(mid) < A.get(mid+1)) lo = mid+1;
      else hi = mid;
    }
    int peak = lo;
    lo = 0;
    hi = peak;
    while (lo <= hi) {
      int mid = (lo + hi)>>1;
      if (A.get(mid) < x) lo = mid+1;
      else if (A.get(mid) > x) hi = mid-1;
      else return mid;
    }
    lo = peak+1;
    hi = n-1;
    while (lo <= hi) {
      int mid = (lo + hi)>>1;
      if (A.get(mid) < x) hi = mid-1;
      else if (A.get(mid) > x) lo = mid+1;
      else return mid;
    }
    return -1;
  }
};