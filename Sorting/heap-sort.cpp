void heapify(vector<int>& A, int n, int i) {
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<n && A[largest]<A[left]) largest=left;
    if (right<n && A[largest]<A[right]) largest=right;
    if (i!=largest) {
        swap(A[i],A[largest]);
        heapify(A,n,largest);
    }
}
void heapSort(vector<int>& A) {
    int n=A.size();
    for (int i=n/2-1; i>=0; --i) heapify(A,n,i);
    for (int i=n-1; i>0; --i) {
        swap(A[0],A[i]);
        heapify(A,i,0);
    }
}
vector<int> sortArray(vector<int>& A) {
    heapSort(A);
    return A;
}