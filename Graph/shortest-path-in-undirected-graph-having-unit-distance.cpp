// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src) {
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }
    vector<int> dist(n, -1);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    int i = 0;
    while (!q.empty()) {
      ++i;
      int k = q.size();
      while (k--) {
        int u = q.front();
        q.pop();
        for (int& v : adj[u]) {
          if (dist[v] == -1) {
            dist[v] = i;
            q.push(v);
          }
        }
      }
    }
    return dist;
  }
};