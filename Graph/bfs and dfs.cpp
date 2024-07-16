// Time  : O(V+2E)
// Space : O(V)
class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V); 
        vis[0] = 1;
        queue<int> q; 
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (auto& v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> ans;
    void dfs(int u, vector<bool>& vis, vector<int> adj[]) {
        vis[u] = 1;
        ans.push_back(u);
        for (int& v : adj[u]) {
            if (!vis[v]) dfs(v, vis, adj);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        dfs(0, vis, adj);
        return ans;
    }
};