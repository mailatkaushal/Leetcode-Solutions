// Time  : O(logn)
// Space : O(1)
class Solution{
public:	
	int findKRotation(int A[], int n) {
    int lo = 0;
    int hi = n-1;
    while (lo < hi) {
      int mid = (lo + hi)>>1;
      if (A[mid] > A[hi]) lo = mid+1;
      else hi = mid;
    }
    return lo;
	}
};