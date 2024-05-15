// Time  : O(logn)
// Space : O(1)
class Solution{
public:
	int count(int A[], int n, int x) {
    int lo = 0;
    int hi = n;
    while (lo < hi) {
      int mid = (lo + hi)>>1;
      if (A[mid] < x) lo = mid+1;
      else hi = mid;
    }
    if (lo == n || A[lo] != x) return 0;
    int first = lo;
    lo = 0;
    hi = n;
    while (lo < hi) {
      int mid = (lo + hi)>>1;
      if (A[mid] <= x) lo = mid+1;
      else hi = mid;
    }
    int last = lo-1;
    return last - first + 1;
	}
};