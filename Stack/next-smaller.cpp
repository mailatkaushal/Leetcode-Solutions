vector<int> nextSmallerElement(vector<int>& A) {
    int n=A.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i=n-1; i>=0; --i) {
        while (!st.empty() && A[i]<=st.top()) st.pop();
        ans[i]=st.empty()?-1:st.top();
        st.push(A[i]);
    }
    return ans;
} 