// Time  : O(n^2)
// Space : O(1)

void bubbleSort(vector<int>& A, int n) {
  for (int i = 0; i < n-1; ++i) {
    bool swapped = false;
    for (int j = 0; j < n-i-1; ++j) {
      if (A[j] > A[j+1]) {
        swap(A[j], A[j+1]);
        swapped = true;
      }
    }
    if (swapped == false)
      break;
  }
}