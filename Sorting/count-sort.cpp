// Time : O(n+k)
void countSort(vector<int>& A) {
  int mi=A[0],ma=A[0];
  for (int i=0; i<A.size(); ++i) {
    mi=min(mi,A[i]);
    ma=max(ma,A[i]);
  }
  int k=ma-mi+1;
  vector<int> C(k);
  for (int a:A) C[a-mi]++;
  int ai=0;
  for (int i=0; i<C.size(); ++i) {
    while (C[i]--) {
      A[ai++]=i+mi;
    }
  }
}