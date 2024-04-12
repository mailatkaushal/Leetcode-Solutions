// Time  : O(n^2)
// Space : O(n)

class Solution {
public:
  // Function to detect cycle in an undirected graph.
  bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V);
    for (int i = 0; i < V; ++i) {
      if (!vis[i]) {
        vis[i] = 1;
        queue<pair<int, int>> q;
        q.push({i, -1});
        while (!q.empty()) {
          auto p = q.front();
          q.pop();
          int u = p.first;
          int parent = p.second;
          for (int& v : adj[u]) {
            if (!vis[v]) {
              q.push({v, u});
              vis[v] = 1;
            }
            else if (parent != v) return true;
          }
        }
      }
    }
    return false;
  }
};