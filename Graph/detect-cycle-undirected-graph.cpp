// Time  : O(V+2E)
// Space : O(V)
class Solution {
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        for (int i=0; i<V; ++i) {
            if (!vis[i]) {
                vis[i] = 1;
                queue<pair<int,int>> q; q.push({i,-1});
                while (!q.empty()) {
                    auto p = q.front(); q.pop();
                    int u = p.first;
                    int parent = p.second;
                    for (auto& v : adj[u]) {
                        if (!vis[v]) {
                            vis[v] = 1;
                            q.push({v,u});
                        }
                        else if (v != parent) return 1;
                    }
                }
            }
        }
        return 0;
    }
};