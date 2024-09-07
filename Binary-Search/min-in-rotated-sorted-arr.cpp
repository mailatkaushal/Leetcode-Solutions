int findMin(vector<int>& A) {
    int lo=0,hi=A.size()-1;
    while (lo<hi) {
        int mid=(lo+hi)>>1;
        if (A[mid]>A[hi]) lo=mid+1;
        else hi=mid;
    }
    return A[lo];
}