// Time  : O(V + E)
// Space : O(V)

class Solution {
public:
  // Function to return a list containing the DFS traversal of the graph.
  vector<int> A;
  void dfs(int u, vector<int> adj[], vector<bool>& vis) {
    vis[u] = 1;
    A.push_back(u);
    for (int& v : adj[u]) {
      if (!vis[v]) 
        dfs(v, adj, vis);
    }
  }
  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> vis(V);
    dfs(0, adj, vis);
    return A;
  }
};