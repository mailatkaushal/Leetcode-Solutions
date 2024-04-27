// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto& x : roads) {
      adj[x[0]].push_back({x[1], x[2]});
      adj[x[1]].push_back({x[0], x[2]});
    }
    vector<long long> ways(n);
    ways[0] = 1;
    vector<long long> dist(n, LLONG_MAX);
    dist[0] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
      auto [du, u] = pq.top();
      pq.pop();
      for (auto& [v, duv] : adj[u]) {
        if (du + duv < dist[v]) {
          dist[v] = du + duv;
          pq.push({dist[v], v});
          ways[v] = ways[u];
        }
        else if (du + duv == dist[v]) ways[v] = (ways[v] + ways[u]) % 1000000007;
      }
    }
    return ways[n-1];
  }
};