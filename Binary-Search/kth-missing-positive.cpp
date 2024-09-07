int findKthPositive(vector<int>& A, int k) {
    int lo=0,hi=A.size()-1;
    while (lo<=hi) {
        int mid=(lo+hi)>>1;
        if (A[mid]-mid-1<k) lo=mid+1;
        else hi=mid-1;
    }
    return k+lo;
}