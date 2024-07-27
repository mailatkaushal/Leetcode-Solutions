// Time  : O(n^2)
// Space : O(1)
void insertionSort(int n, vector<int>& A) {
    for (int i=1; i<n; ++i) {
        int x=A[i];
        int j=i-1;
        while (j>=0 && A[j]>x) {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}