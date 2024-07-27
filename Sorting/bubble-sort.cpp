// Time  : O(n^2)
// Space : O(1)
void bubbleSort(vector<int>& A, int n) {
    for (int i=0; i<=n-2; ++i) {
        bool swapped=0;
        for (int j=0; j<=n-2-i; ++j) {
            if(A[j]>A[j+1]) {
                swap(A[j],A[j+1]);
                swapped=1;
            }
        }
        if (swapped==0) break;
    }
}