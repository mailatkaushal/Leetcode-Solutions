// Time  : O(V+2E)
// Space : O(V)
class Solution{
public:
    void dfs(int u, vector<bool>& vis, vector<int> adj[], stack<int>& st) {
        vis[u] = 1;
        for (int& v : adj[u]) {
            if (!vis[v]) dfs(v, vis, adj, st);
        }
        st.push(u);
    }
    vector<int> topoSort(int V, vector<int> adj[]) {
      stack<int> st;
      vector<bool> vis(V);
      for (int i=0; i<V; ++i) {
          if (!vis[i]) dfs(i, vis, adj, st);
      }
      vector<int> ans;
      while (!st.empty()) {
          ans.push_back(st.top()); st.pop();
      }
      return ans;
    }
};
// Kahn's Algo / BFS
class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> inDeg(V);
        for (int i=0; i<V; ++i) {
            for (auto& j : adj[i]) inDeg[j]++;
        }
        queue<int> q;
        for (int i=0; i<V; ++i) {
            if (inDeg[i] == 0) q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ans.push_back(u);
            for (int& v : adj[u]) {
                if (--inDeg[v] == 0) q.push(v);
            }
        }
        return ans;
    }
};