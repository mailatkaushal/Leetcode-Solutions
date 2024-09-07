bool searchMatrix(vector<vector<int>>& M, int target) {
    int m=M.size(),n=M[0].size();
    int lo=0,hi=m*n-1;
    while (lo<=hi) {
        int mid=(lo+hi)>>1;
        int x=mid/n;
        int y=mid%n;
        if (M[x][y]==target) return 1;
        else if (M[x][y]<target) lo=mid+1;
        else hi=mid-1;
    }
    return 0;
}