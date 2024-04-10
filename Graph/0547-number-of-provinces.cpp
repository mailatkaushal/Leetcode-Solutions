// Time  : O(2n+2e)
// Space : O(n)

class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int cnt = 0;
    queue<int> q;
    vector<bool> visited(n);
    for (int u = 0; u < n; ++u) {
      if (!visited[u]) {
        ++cnt;
        q.push(u);
        visited[u] = 1;
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int v = 0; v < n; ++v) {
            if (isConnected[u][v] && !visited[v]) {
              visited[v] = 1;
              q.push(v);
            }
          }
        }
      }
    }
    return cnt;
  }
};

// Time  : O(2n+2e)
// Space : O(n)

class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int cnt = 0;
    vector<vector<int>> adj(n);
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        if (isConnected[u][v]) {
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
      }
    }
    queue<int> q;
    vector<bool> visited(n);
    for (int u = 0; u < n; ++u) {
      if (!visited[u]) {
        ++cnt;
        visited[u] = 1;
        q.push(u);
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int& v : adj[u]) {
            if (!visited[v]) {
              visited[v] = 1;
              q.push(v);
            }
          }
        }
      }
    }
    return cnt;
  }
};

// Time  : O(2n+2e)
// Space : O(n)

class Solution {
public:
  void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = 1;
    for (int& v : adj[u]) {
      if (!visited[v])
        dfs(v, adj, visited);
    }
  }

  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int cnt = 0;
    vector<vector<int>> adj(n);
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        if (isConnected[u][v]) {
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
      }
    }
    vector<bool> visited(n);
    for (int u = 0; u < n; ++u) {
      if (!visited[u]) {
        ++cnt;
        dfs(u, adj, visited);
      }
    }
    return cnt;
  }
};