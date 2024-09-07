int search(vector<int>& A, int x) {
    int lo=0,hi=A.size()-1;
    while (lo<=hi) {
        int mid=(lo+hi)>>1;
        if (A[mid]==x) return mid;
        if (A[lo]<=A[mid]) {
            if (A[lo]<=x && x<A[mid]) hi=mid-1;
            else lo=mid+1;
        }
        else {
            if (A[mid]<x && x<=A[hi]) lo=mid+1;
            else hi=mid-1;
        }
    }
    return -1;
}