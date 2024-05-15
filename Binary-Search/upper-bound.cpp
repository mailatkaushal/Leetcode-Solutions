// Time  : O(logn)
// Space : O(1)
int upperBound(vector<int>& A, int x, int n){
	int lo = 0;
	int hi = n;
	while (lo < hi) {
		int mid = (lo + hi)>>1;
		if (A[mid] <= x) lo = mid+1;
		else hi = mid;
	}
	return lo;
}