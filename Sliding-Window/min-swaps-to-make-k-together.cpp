int minSwap(vector<int>& A, int k) {
    int wS=0;
    for (int i=0; i<A.size(); ++i) if (A[i]<=k) wS++;
    int bad=0;
    for (int i=0; i<wS; ++i) if (A[i]>k) ++bad;
    int ans=bad;
    for (int i=0,j=wS; j<A.size(); ++i,++j){
        if (A[i]>k) --bad;
        if (A[j]>k) ++bad;
        ans=min(ans,bad);
    }
    return ans;
}