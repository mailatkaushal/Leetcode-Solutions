int lb(vector<int>& A, int x) {
		int lo=0,hi=A.size();
		while (lo<hi) {
				int mid=(lo+hi)>>1;
				if (A[mid]<x) lo=mid+1;
				else hi=mid;
		}
		return lo;
}