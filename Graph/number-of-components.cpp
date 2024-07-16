// Time  : O(V+2E))
// Space : O(V)
class Solution {
public:
  int findCircleNum(vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<vector<int>> adj(n);
    for (int i=0; i<n; ++i) {
      for (int j=0; j<n; ++j) {
        if (adjMatrix[i][j]) { adj[i].push_back(j); adj[j].push_back(i); }
      }
    }
    int ans = 0;
    vector<bool> vis(n);
    for (int i=0; i<n; ++i) {
      if (!vis[i]) {
        ans++;
        vis[i] = 1;
        queue<int> q; q.push(i);
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int& v : adj[u]) {
            if (!vis[v]) {
              vis[v] = 1;
              q.push(v);
            }
          }
        }
      }
    }
    return ans;
  }
};