// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n-1; ++i) {
      for (int j = i+1; j < n; ++j) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        int x2 = points[j][0];
        int y2 = points[j][1];
        int dij = abs(x1 - x2) + abs(y1 - y2);
        adj[i].push_back({j, dij});
        adj[j].push_back({i, dij});
      }
    }
    vector<int> vis(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int ans = 0;
    while (!pq.empty()) {
      auto [uwt, u] = pq.top();
      pq.pop();
      if (!vis[u]) {
        vis[u] = 1;
        ans += uwt;
        for (auto& [v, vwt] : adj[u]) {
          if (!vis[v]) pq.push({vwt, v});
        }
      }
    }
    return ans;
  }
};