// Time  : O(V + E)
// Space : O(V)

class Solution {
public:
  // Function to return a list containing the DFS traversal of the graph.
  void dfs(int u, vector<int> adj[], vector<bool>& visited, vector<int>& res) {
    visited[u] = 1;
    res.push_back(u);
    for (int& v : adj[u]) {
      if (!visited[v]) 
        dfs(v, adj, visited, res);
    }
  }

  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> res;
    vector<bool> visited(V);
    dfs(0, adj, visited, res);
    return res;
  }
};