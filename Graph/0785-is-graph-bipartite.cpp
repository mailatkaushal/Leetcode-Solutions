// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, 0);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (!color[i]) {
        color[i] = 1;
        q.push(i);
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int& v : graph[u]) {
            if (!color[v]) {
              color[v] = -color[u]; 
              q.push(v);
            }
            else if (color[u] == color[v]) return false;
          }
        }
      }
    }
    return true;
  }
};