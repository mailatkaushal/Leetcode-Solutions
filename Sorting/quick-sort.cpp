// Time  : O(nlogn)
// Space : O(1)

int partitionArray(vector<int>& A, int l, int r) {
  int p = l, i = l, j = r;
  while (i < j) {
    while (i <= r-1 && A[i] <= A[p]) ++i;
    while (A[j] > A[p]) --j;
    if (i < j) 
      swap(A[i], A[j]);
  }
  swap(A[p], A[j]);
  return j;
}

void qS(vector<int>& A, int l, int r) {
  if (l < r) {
    int pivot = partitionArray(A, l, r);
    qS(A, l, pivot-1);
    qS(A, pivot+1, r);
  }
}

vector<int> quickSort(vector<int>& A) {
  qS(A, 0, A.size()-1);
  return A;
}