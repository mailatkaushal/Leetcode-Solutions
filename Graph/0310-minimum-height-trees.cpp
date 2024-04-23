// Time  : O(n)
// Space : O(n)
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    vector<vector<int>> adj(n);
    vector<int> indeg(n);
    for (auto& e : edges) {
      ++indeg[e[0]];
      ++indeg[e[1]];
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (indeg[i] == 1) 
        q.push(i);
    }
    while (n > 2) {
      int k = q.size();
      n -= k;
      while (k--) {
        int x = q.front();
        q.pop();
        for (int& y : adj[x]) {
          if (--indeg[y] == 1) 
            q.push(y);
        }
      }
    }
    vector<int> ans;
    while (!q.empty()) {
      ans.push_back(q.front());
      q.pop();
    }
    return ans;
  }
};