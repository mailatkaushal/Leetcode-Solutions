// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  void topoSort(int u, vector<vector<pair<int, int>>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[u] = 1;
    for (auto& p : adj[u]) {
      int v = p.first;
      if (!vis[v]) 
        topoSort(v, adj, vis, st);
    }
    st.push(u);
  }
  vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
    vector<vector<pair<int, int>>> adj(n);
    vector<int> indeg(n);
    for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});
    vector<bool> vis(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        topoSort(i, adj, vis, st);
      }
    }
    vector<int> dist(n, 1e9);
    dist[0] = 0;
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      for (auto& p : adj[u]) {
        int v = p.first;
        int w = p.second;
        dist[v] = min(dist[v], dist[u] + w);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (dist[i] == 1e9)
        dist[i] = -1;
    }
    return dist;
  }
};