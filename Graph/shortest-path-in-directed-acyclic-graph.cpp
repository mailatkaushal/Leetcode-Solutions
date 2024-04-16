// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  vector<int> shortestPath(int n,int m, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(n);
    vector<int> indeg(n);
    for (auto& e : edges) {
      int u = e[0];
      int v = e[1];
      int w = e[2];
      adj[u].push_back({v, w});
      ++indeg[v];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);
    vector<int> vec(n);
    int x = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      vec[x++] = u;
      for (auto& p : adj[u]) {
        int v = p.first;
        if (--indeg[v] == 0) q.push(v);
      }
    }
    x = 0;
    vector<int> dist(n, 1e9);
    dist[0] = 0;
    while (x < n) {
      int u = vec[x++];
      for (auto& p : adj[u]) {
        int v = p.first;
        int w = p.second;
        dist[v] = min(dist[v], dist[u] + w);
      }
    }
    for (int i = 0; i < n; ++i) if (dist[i] == 1e9) dist[i] = -1;
    return dist;
  }
};