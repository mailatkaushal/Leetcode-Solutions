double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    if (A.size()>B.size()) return findMedianSortedArrays(B,A);
    int n1=A.size(),n2=B.size();
    int n=n1+n2;
    int lo=0,hi=n1;
    double median;
    while (lo<=hi) {
        int mid1=(lo+hi)>>1;
        int mid2=((n+1)/2)-mid1;
        int l1=(mid1==0)?INT_MIN:A[mid1-1];
        int l2=(mid2==0)?INT_MIN:B[mid2-1];
        int r1=(mid1==n1)?INT_MAX:A[mid1];
        int r2=(mid2==n2)?INT_MAX:B[mid2];
        if (l1<=r2 && l2<=r1) {
            if (n%2==0) median=(max(l1,l2)+min(r1,r2))/2.0;
            else median=max(l1,l2);
            break;
        }
        if (l1>r2) hi=mid1-1;
        else lo=mid1+1;
    }
    return median;
}