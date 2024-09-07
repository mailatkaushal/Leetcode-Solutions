bool searchMatrix(vector<vector<int>>& M, int target) {
    int i=0,j=M[0].size()-1;
    while (i<M.size() && j>=0) {
        if (M[i][j]==target) return 1;
        else if (M[i][j]<target) ++i;
        else --j;
    }
    return 0;
}