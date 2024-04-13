// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);
    vector<int> indeg(n);
    for (auto& v : prerequisites) {
      adj[v[1]].push_back(v[0]);
      ++indeg[v[0]];
    }
    queue<int> q;
    for (int u = 0; u < n; ++u) {
      if (indeg[u] == 0) 
        q.push(u);
    }
    vector<int> topo;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      topo.push_back(u);
      for (int& v : adj[u]) {
        --indeg[v];
        if (indeg[v] == 0) 
          q.push(v);
      }
    }
    if (topo.size() < n) return {};
    return topo;
  }
};