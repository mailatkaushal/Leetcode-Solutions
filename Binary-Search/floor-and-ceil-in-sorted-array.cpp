// Time  : O(logn)
// Space : O(1)

pair<int, int> getFloorAndCeil(vector<int>& A, int n, int x) {
  // Floor - largest element in the array <= x
  // Ceil - smallest element in the array >= x
	int lo = 0, hi = n - 1;
	int floor = -1, ceil = -1;
	
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (A[mid] <= x) {
			floor = A[mid];
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}

	lo = 0, hi = n - 1;

	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (A[mid] < x) 
			lo = mid + 1;
		else {
			ceil = A[mid];
			hi = mid - 1;
		}
	}

	return {floor, ceil};
}