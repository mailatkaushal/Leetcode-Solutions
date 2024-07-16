class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> ind(n);
        for (auto& e : edges) { 
            adj[e[0]].push_back({e[1],e[2]}); 
            ++ind[e[1]];
        }
        queue<int> q;
        for (int i=0; i<n; ++i) {
            if (ind[i] == 0) q.push(i);
        }
        queue<int> Q;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            Q.push(u);
            for (auto& it : adj[u]) {
                int v = it.first;
                if (--ind[v] == 0) q.push(v);
            }
        }
        while (!Q.empty()) {
            if (Q.front() != 0) Q.pop();
            else break;
        }
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (auto& it : adj[u]) {
                int v = it.first;
                int duv = it.second;
                dist[v] = min(dist[v], dist[u] + duv);
            }
        }
        for (int i=0; i<n; ++i) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};