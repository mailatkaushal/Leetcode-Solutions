class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(src);
        vector<int> dist(n,-1);
        dist[src] = 0;
        int d = 1;
        while (!q.empty()) {
            int z = q.size();
            while (z--) {
                int u = q.front(); q.pop();
                for (auto& v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = d;
                        q.push(v);
                    }
                }
            }
            ++d;
        }
        return dist;
    }
};