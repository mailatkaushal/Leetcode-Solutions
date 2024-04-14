// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  vector<int> shortestPath(vector<vector<int>>& edges, int n ,int m, int src) {
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<int> dist(n, -1);
    dist[src] = 0;
    vector<bool> vis(n);
    vis[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int& v : adj[u]) {
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
          dist[v] = dist[u] + 1;
        }
      }
    }
    return dist;
  }
};