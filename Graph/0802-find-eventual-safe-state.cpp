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

// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> revadj(n);
    vector<int> outdeg(n);
    for (int i = 0; i < n; ++i) {
      outdeg[i] = graph[i].size();
      for (int& j : graph[i]) revadj[j].push_back(i);
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (outdeg[i] == 0) {
        q.push(i);
      }
    }
    vector<bool> safe(n);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      safe[u] = 1;
      for (int& v : revadj[u]) {
        --outdeg[v];
        if (outdeg[v] == 0) q.push(v);
      }
    }
    vector<int> safeNodes;
    for (int i = 0; i < n; ++i) {
      if (safe[i]) {
        safeNodes.push_back(i);
      }
    } 
    return safeNodes;
  }
};