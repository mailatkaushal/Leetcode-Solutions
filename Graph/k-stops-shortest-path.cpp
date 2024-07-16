class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
    for (auto& f : flights) {
      adj[f[0]].push_back({f[1],f[2]});
    }
    vector<int> dist(n,1e9);
    queue<pair<int,int>> q;
    dist[src] = 0;
    q.push({src,0});
    int stops = 0;
    while (!q.empty() && stops<=k) {
      int z = q.size();
      while (z--) {
        auto [u,du] = q.front(); q.pop();
        for (auto& [v,duv] : adj[u]) {
          if (du + duv < dist[v]) {
            dist[v] = du + duv;
            q.push({v,dist[v]});
          }
        }
      }
      ++stops;
    }
    return dist[dst] == 1e9 ? -1 : dist[dst];
  }
};