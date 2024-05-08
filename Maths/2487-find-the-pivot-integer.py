# Time  : O(logn)
# Space : O(1)
class Solution {
public:
  int pivotInteger(int n) {
    int lo = 1;
    int hi = n;
    while (lo <= hi) {
      int mid = (lo + hi)/2;
      int left = mid*(mid + 1)/2;
      int right = n*(n + 1)/2 - (mid-1)*mid/2;
      if (left < right) lo = mid+1;
      else if (left > right) hi = mid-1;
      else return mid;
    }
    return -1;
  }
};