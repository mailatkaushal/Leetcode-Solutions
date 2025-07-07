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