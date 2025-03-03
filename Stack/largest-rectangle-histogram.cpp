int largestRectangleArea(vector<int>& A) {
    int n=A.size();
    vector<int> pse(n,-1);
    stack<int> st;
    for (int i=0; i<n; ++i) {
        while (!st.empty() && A[st.top()]>=A[i]) st.pop();
        if (!st.empty()) pse[i]=st.top();
        st.push(i);
    }
    vector<int> nse(n,n);
    st=stack<int>();
    for (int i=n-1; i>=0; --i) {
        while (!st.empty() && A[i]<=A[st.top()]) st.pop();
        if (!st.empty()) nse[i]=st.top();
        st.push(i);
    }
    int ans=0;
    for (int i=0; i<n; ++i) {
        ans=max(ans,(nse[i]-pse[i]-1)*A[i]);
    }
    return ans;
}