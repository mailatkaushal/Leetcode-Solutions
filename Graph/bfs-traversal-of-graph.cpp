// Time  : O(n+2e)
// Space : O(n)

class Solution {
public:
  // Function to return Breadth First Traversal of given graph.
  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> res;
    queue<int> q;
    q.push(0);
    vector<int> visited(V);
    visited[0] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      res.push_back(u);
      for (int& v : adj[u]) {
        if (!visited[v]) {
          q.push(v);
          visited[v] = 1;
        }
      }
    }
    return res;
  }
};