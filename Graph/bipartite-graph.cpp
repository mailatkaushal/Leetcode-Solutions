class Solution {
public:
  bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n);
    for (int i=0; i<n; ++i) {
      if (!color[i]) {
        color[i] = 1;
        queue<int> q; q.push(i);
        while (!q.empty()) {
          int u = q.front(); q.pop();
          for (int& v : adj[u]) {
            if (!color[v]) {
              color[v] = (color[u] == 1) ? 2 : 1;
              q.push(v);
            }
            else if (color[u] == color[v]) return 0;
          }
        }
      }
    }
    return 1;
  }
};