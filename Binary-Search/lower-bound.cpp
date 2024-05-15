// Time  : O(logn)
// Space : O(1)
int lowerBound(vector<int>& A, int n, int x) {
	int lo = 0;
	int hi = n;
	while (lo < hi) {
		int mid = (lo + hi)>>1;
		if (A[mid] < x) lo = mid+1;
		else hi = mid;
	}
	return lo;
}