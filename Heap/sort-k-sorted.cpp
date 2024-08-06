vector<int> sort(vector<int>& A, int k) {
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i=0; i<A.size(); ++i) {
        pq.push(A[i]);
        if (pq.size()>k) {
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while (pq.size()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}