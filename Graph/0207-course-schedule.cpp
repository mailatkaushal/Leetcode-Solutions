// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);
    vector<int> indeg(n);
    for (auto& v : prerequisites) {
      adj[v[1]].push_back(v[0]);
      ++indeg[v[0]];
    }
    queue<int> q;
    for (int u = 0; u < n; ++u) {
      if (indeg[u] == 0) 
        q.push(u);
    }
    int cnt = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ++cnt;
      for (int& v : adj[u]) {
        --indeg[v];
        if (indeg[v] == 0) 
          q.push(v);
      }
    }
    return cnt == n;
  }
};