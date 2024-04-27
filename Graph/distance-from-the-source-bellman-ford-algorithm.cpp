// Time  : O(n^3)
// Space : O(1)
class Solution {
public:
  vector<int> bellman_ford(int n, vector<vector<int>>& edges, int src) {
    vector<int> dist(n, 1e8);
    dist[src] = 0;
    // Relax edges for (n-1) iterations
    for (int i = 0; i < n-1; ++i) {
      for (auto& e : edges) {
        int u = e[0];
        int v = e[1];
        int duv = e[2];
        if (dist[u] != 1e8 && dist[u] + duv < dist[v]) dist[v] = dist[u] + duv;
      }
    }
    // Nth relaxation to check negative cycle
    for (auto& e : edges) {
      int u = e[0];
      int v = e[1];
      int duv = e[2];
      if (dist[u] != 1e8 && dist[u] + duv < dist[v]) return {-1};
    }
    return dist;
  }
};