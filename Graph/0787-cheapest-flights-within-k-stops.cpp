// Time  : O(n^2)
// Time  : O(n^2)
class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});
    queue<pair<int, int>> q;
    vector<int> dist(n, 1e9);
    q.push({src, 0});
    dist[src] = 0;
    int stops = -1;
    while (!q.empty()) {
      ++stops;
      if (stops > k) break;
      int x = q.size();
      while (x--) {
        auto [u, du] = q.front();
        q.pop();
        for (auto& [v, duv] : adj[u]) {
          if (du + duv < dist[v]) {
            dist[v] = du + duv;
            q.push({v, dist[v]});
          }
        }
      }
    }
    if (dist[dst] == 1e9) return -1;
    return dist[dst];
  }
};