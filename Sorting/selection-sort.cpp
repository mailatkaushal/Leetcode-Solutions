// Time  : O(n^2)
// Space : O(1)
void selectionSort(vector<int>& A, int n) {
    for (int i=0; i<=n-2; ++i) {
        int mi=i;
        for (int j=i+1; j<n; ++j) {
            if (A[mi]>A[j]) mi=j; 
        }
        swap(A[i],A[mi]);
    }
}