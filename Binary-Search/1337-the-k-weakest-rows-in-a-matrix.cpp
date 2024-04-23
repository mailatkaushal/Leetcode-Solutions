// Time  : O(m*logn + m*logm)
// Space : O(m)
class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>>& M, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int m = M.size();
    int n = M[0].size();
    for (int i = 0; i < m; ++i) {
      int lo = 0, hi = n-1;
      while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (M[i][mid] == 1) lo = mid+1;
        else hi = mid; 
      }
      pq.push({lo, i});
    }
    vector<int> ans;
    while (!pq.empty() && k--) {
      auto [ones, idx] = pq.top();
      pq.pop();
      ans.push_back(idx);
    }
    return ans;
  }
};