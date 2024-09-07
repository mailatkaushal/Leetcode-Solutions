// Time  : O(logn)
int bs(vector<int>& A, int x) {
    int lo=0,hi=A.size()-1;
    while (lo<=hi) {
      int mid=(lo+hi)>>1;
      if (A[mid]<x) lo=mid+1;
      else if (A[mid]>x) hi=mid-1;
      else return mid;
    }
    return -1;
}