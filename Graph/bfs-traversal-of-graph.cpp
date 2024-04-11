// Time  : O(V + E)
// Space : O(V)

class Solution {
public:
  // Function to return Breadth First Traversal of given graph.
  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> A;
    vector<bool> vis(V);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      A.push_back(u);
      for (int& v : adj[u]) {
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
    return A;
  }
};