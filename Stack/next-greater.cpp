vector<long long> nextGreaterElement(vector<long long>& A){
    int n=A.size();
    vector<long long> ans(n);
    stack<long long> st;
    for (int i=n-1; i>=0; --i) {
        while (!st.empty() && A[i]>=st.top()) st.pop();
        ans[i]=st.empty()?-1:st.top();
        st.push(A[i]);
    }
    return ans;
}