int kthSmallest(vector<int>& A, int k) {
    priority_queue<int> pq;
    for (int i=0; i<A.size(); ++i) {
        pq.push(A[i]);
        if (pq.size()>k) pq.pop();
    }
    return pq.top();
}