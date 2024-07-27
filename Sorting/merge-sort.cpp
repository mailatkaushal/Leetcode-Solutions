// Time  : O(nlogn)
// Space : O(n)
void merge(vector<int>& A, int l, int mid, int r) {
  vector<int> B(r-l+1);
  int i=l, j=mid+1, k=0;
  while (i<=mid && j<=r) {
    if (A[i]<=A[j]) B[k++] = A[i++];
    else B[k++] = A[j++];
  }
  while (i<=mid) B[k++] = A[i++];
  while (j<=r) B[k++] = A[j++];
  for (int i=l; i<=r; ++i) A[i] = B[i-l];
}
void mergeSort(vector<int>& A, int l, int r) {
  if (l<r) {
    int mid = (l+r)>>1;
    mergeSort(A,l,mid);
    mergeSort(A,mid+1,r);
    merge(A,l,mid,r);
  }
}
vector<int> sortArray(vector<int>& A) {
  mergeSort(A,0,A.size()-1);
  return A;
}