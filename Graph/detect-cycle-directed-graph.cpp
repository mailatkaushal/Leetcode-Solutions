class Solution {
public: 
    bool dfs(int u, vector<bool>& vis, vector<bool>& pathVis, vector<int> adj[]) {
        vis[u] = 1;
        pathVis[u] = 1;
        for (int& v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, vis, pathVis, adj)) return 1;
            }
            else if (pathVis[v]) return 1;
        }
        pathVis[u] = 0;
        return 0;
    }  
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        for (int i=0; i<V; ++i) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj)) return 1;
            }
        }
        return 0;
    }
};
class Solution {
public: 
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> ind(V);
        for (int i=0; i<V; ++i) {
            for (int& j : adj[i]) ind[j]++;
        }
        queue<int> q;
        for (int i=0; i<V; ++i) {
            if (ind[i] == 0) q.push(i);
        }
        int x = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ++x;
            for (int& v : adj[u]) {
                ind[v]--;
                if (ind[v] == 0) q.push(v);
            }
        }
        return x<V;
    }
};