// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int n, vector<vector<int>> adj[]) {
    vector<bool> vis(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int ans = 0;
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int uwt = p.first;
      int u = p.second;
      if (!vis[u]) {
        vis[u] = 1;
        ans += uwt;
        for (auto& it : adj[u]) {
          int v = it[0];
          int vwt = it[1];
          if (!vis[v]) pq.push({vwt, v});
        }
      }
    }
    return ans;
  }
};