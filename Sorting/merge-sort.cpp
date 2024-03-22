// Time  : O(nlogn)
// Space : O(n)

void merge(vector<int>& A, int l, int mid, int r) {
  vector<int> a(r-l+1);
  int i = l, j = mid+1, x = 0;
  while (i <= mid && j <= r) {
    if (A[i] <= A[j])
      a[x++] = A[i++];
    else
      a[x++] = A[j++];
  }
  while (i <= mid) a[x++] = A[i++];
  while (j <= r) a[x++] = A[j++];
  for (int i = l; i <= r; ++i)
    A[i] = a[i-l];
}

void mS(vector<int>& A, int l, int r) {
  if (l == r) return;
  int mid = (l + r) / 2;
  mS(A, l, mid);
  mS(A, mid+1, r);
  merge(A, l, mid, r);
}

void mergeSort(vector<int>& A, int n) {
  mS(A, 0, n-1);
}