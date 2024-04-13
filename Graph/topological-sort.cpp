// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
  void dfs(int u, vector<int> adj[], vector<bool>& vis, stack<int>& st) {
    vis[u] = 1;
    for (int& v : adj[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        dfs(v, adj, vis, st);
      }
    }
    st.push(u);
  }
	//Function to return list containing vertices in Topological order. 
  vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> vis(V);
    stack<int> st;
	 for (int i = 0; i < V; ++i) {
      if (!vis[i]) 
        dfs(i, adj, vis, st);
    }
    vector<int> topo;
    while (!st.empty()) {
      topo.push_back(st.top());
      st.pop();
    }
    return topo;
  }
};

// Time  : O(n^2)
// Space : O(n)
// Kahn's Algorithm
class Solution {
public:
  //Function to return list containing vertices in Topological order. 
  vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> ind(V);
    for (int u = 0; u < V; ++u) {
      for (int& v : adj[u]) {
        ++ind[v];
      }
    }
    queue<int> q;
    for (int u = 0; u < V; ++u) {
      if (ind[u] == 0)
        q.push(u);
    }
    vector<int> topo;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      topo.push_back(u);
      for (int& v : adj[u]) {
        --ind[v];
        if (ind[v] == 0) q.push(v);
      }
    }
    return topo;
  }
};