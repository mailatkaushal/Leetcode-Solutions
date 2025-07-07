int floor(vector<int>& A, int x) {
    int lo=0,hi=A.size()-1;
    while (lo<=hi) {
        int mid=(lo+hi)>>1;
        if (A[mid]<=x) lo=mid+1;
        else hi=mid-1;
    }
    return hi==-1?hi:A[hi];
}
int ceil(vector<int>& A, int x) {
    int lo=0,hi=A.size()-1;
    while (lo<=hi) {
        int mid=(lo+hi)>>1;
        if (A[mid]<x) lo=mid+1;
        else hi=mid-1;
    }
    return lo==A.size()?-1:A[lo];
}