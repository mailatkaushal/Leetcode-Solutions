// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int cnt = 0;
    vector<bool> vis(n);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        ++cnt;
        vis[i] = 1;
        q.push(i);
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int i = 0; i < n; ++i) {
            if (isConnected[u][i] && !vis[i]) {
              vis[i] = 1;
              q.push(i);
            }
          }
        }
      }
    }
    return cnt;
  }
};

// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int cnt = 0;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isConnected[i][j]) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    vector<bool> vis(n);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        ++cnt;
        vis[i] = 1;
        q.push(i);
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
    return cnt;
  }
};

// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  int cnt = 0;
  void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = 1;
    for (int& v : adj[u]) {
      if (!vis[v]) 
        dfs(v, adj, vis);
    }
  }
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isConnected[i][j]) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        ++cnt;
        dfs(i, adj, vis);
      }
    }
    return cnt;
  }
};