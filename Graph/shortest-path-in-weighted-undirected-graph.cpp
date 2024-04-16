// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(n+1);
    for (auto& e : edges) {
      adj[e[0]].push_back({e[1], e[2]});
      adj[e[1]].push_back({e[0], e[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    vector<int> dist(n+1, 1e9);
    dist[1] = 0;
    vector<int> parent(n+1, -1);
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int du = p.first;
      int u = p.second;
      for (auto& it : adj[u]) {
        int v = it.first;
        int duv = it.second;
        if (du + duv < dist[v]) {
          dist[v] = du + duv;
          pq.push({dist[v], v});
          parent[v] = u;
        }
      }
    }
    if (dist[n] == 1e9) return {-1};
    vector<int> path;
    int i = n;
    while (parent[i] != -1) {
      path.push_back(i);
      i = parent[i];
    }
    path.push_back(1);
    path.push_back(dist[n]);
    reverse(path.begin(), path.end());
    return path;
  }
};