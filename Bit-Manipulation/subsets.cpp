// Time  : O(n*(2^n))
// Space : O(n*(2^n))
vector<vector<int>> ans;
void f(vector<int>& A, int i, vector<int> a) {
    if (i==A.size()) {
        ans.push_back(a);
        return;
    }
    f(A,i+1,a);
    a.push_back(A[i]);
    f(A,i+1,a);
}
vector<vector<int>> subsets(vector<int>& A) {
    f(A,0,{});
    return ans;
}

// Time  : O(n*(2^n))
// Space : O(n*(2^n))
vector<vector<int>> subsets(vector<int>& A) {
    int n=A.size();
    int p=1<<n;
    vector<vector<int>> ans(p);
    for (int i=0; i<p; ++i) {
        vector<int> a;
        for (int j=0; j<n; ++j) {
            if ((i>>j)&1) a.push_back(A[j]);
        }
        ans[i]=a;
    }
    return ans;
}