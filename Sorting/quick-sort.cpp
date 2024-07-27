// Time  : O(nlogn)
// Space : O(1)
int partitionArray(vector<int>& A, int l, int r) {
  int p=l, i=l, j=r;
  while (i<j) {
    while (i<=j && A[p]>=A[i]) ++i;
    while (A[j]>A[p]) --j;
    if (i<j) swap(A[i],A[j]);
  }
  swap(A[p],A[j]);
  return j;
}
void quickSort(vector<int>& A, int l, int r) {
  if (l<r) {
    int pivot = partitionArray(A,l,r);
    quickSort(A,l,pivot-1);
    quickSort(A,pivot+1,r);
  }
}
vector<int> sortArray(vector<int>& A) {
  quickSort(A,0,A.size()-1);
  return A;
}