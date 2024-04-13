// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  bool dfs(int u, vector<int> adj[], vector<bool>& vis, vector<bool>& pathVis) {
    vis[u] = 1;
    pathVis[u] = 1;
    for (int& v : adj[u]) {
      if (!vis[v] && dfs(v, adj, vis, pathVis)) return true;
      else if (pathVis[v]) return true;
    }
    pathVis[u] = false;
    return false;
  }
  // Function to detect cycle in a directed graph.
  bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> vis(V);
    vector<bool> pathVis(V);
    for (int i = 0; i < V; ++i) {
      if (!vis[i] && dfs(i, adj, vis, pathVis)) return true;
    }
    return false;
  }
};

// Time  : O(n^2)
// Space : O(n)
class Solution {
public: 
  // Function to detect cycle in a directed graph.
  bool isCyclic(int V, vector<int> adj[]) {
    vector<int> ind(V);
    for (int u = 0; u < V; ++u) {
      for (int& v : adj[u]) 
        ++ind[v];
    }
    queue<int> q;
    for (int u = 0; < V; ++u) {
      if (ind[u] == 0)
        q.push(u);
    }
    int cnt = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ++cnt;
      for (int& v : adj[u]) {
        --ind[v];
        if (ind[v] == 0) q.push(v);
      }
    }
    return cnt < V;
  }
};