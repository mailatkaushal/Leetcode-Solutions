// Time  : O(n^2)
// Space : O(1)

void selectionSort(vector<int>& A) {
  int n = A.size();
  for (int i = 0; i < n-1; ++i) {
    int mi = i;
    for (int j = i+1; j < n; ++j) {
      if (A[j] < A[mi])
        mi = j;
    }
    swap(A[i], A[mi]);
  }
}