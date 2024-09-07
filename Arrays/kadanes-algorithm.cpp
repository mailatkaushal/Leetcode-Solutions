long long maxSubarraySum(vector<int>& A) {
    long long ans=LLONG_MIN;
    long long sum=0;
    for(int i=0;i<A.size();++i){
        sum+=A[i];
        ans=max(ans,sum);
        if(sum<0) sum=0;
    }
    return ans;
}