// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  bool dfs(int u, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& safe) {
    vis[u] = 1;
    pathVis[u] = 1;
    for (int& v : graph[u]) {
      if (!vis[v] && dfs(v, graph, vis, pathVis, safe)) 
        return true;
      if (pathVis[v] == 1) 
        return true;
    }
    safe[u] = true;
    pathVis[u] = 0;
    return false;
  }

  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n);
    vector<int> pathVis(n);
    vector<int> safe(n);
    for (int i = 0; i < n; ++i) {
      if (!vis[i])
        dfs(i, graph, vis, pathVis, safe); 
    }
    vector<int> safeNodes;
    for (int i = 0; i < n; ++i) {
      if (safe[i]) 
        safeNodes.push_back(i);
    }
    return safeNodes;
  }
};