// Time  : O(V^2)
// Space : O(V^2)
class Solution {
public:
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int s) {
    vector<int> dist(V, 1e9);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int du = p.first;
      int u = p.second;
      for (auto& it : adj[u]) {
        int duv = it[1];
        int v = it[0];
        if (du + duv < dist[v]) {
          dist[v] = du + duv;
          pq.push({dist[v], v});
        }
      }
    }
    return dist;
  }
};