// Time  : O(n^2)
// Time  : O(n^2)
class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});
    vector<int> D(n, 1e9);
    D[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    int stops = 0;
    while (!q.empty()) {
      if (stops > k) break;
      int z = q.size();
      while (z--) {
        auto [u, du] = q.front();
        q.pop();
        for (auto& [v, duv] : adj[u]) {
          if (du + duv < D[v]) {
            D[v] = du + duv;
            q.push({v, D[v]});
          }
        }
      }
      ++stops;
    }
    if (D[dst] == 1e9) return -1;
    return D[dst];
  }
};