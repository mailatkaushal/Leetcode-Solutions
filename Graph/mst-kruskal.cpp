// Time  : O(ElogE)
// Space : O(E)
class DS {
public:
    vector<int> size, parent;
    DS (int n) {
        size.resize(n+1,1);
        parent.resize(n+1);
        for (int i=1; i<=n; ++i) parent[i] = i;
    }
    int findPar(int x) {
        if (x==parent[x]) return x;
        return parent[x] = findPar(parent[x]);
    }
    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu==pv) return;
        if (size[pu]<size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> edges;
        for (int u=0; u<V; ++u) {
            for (auto& it : adj[u]) {
                int v = it[0];
                int w = it[1];
                edges.push_back({w,u,v});
            }
        }
        sort(edges.begin(), edges.end());
        DS ds(V);
        int ans = 0;
        for (auto& e : edges) {
            if (ds.findPar(e[1]) != ds.findPar(e[2])) {
                ans += e[0];
                ds.unionBySize(e[1], e[2]);
            }
        }
        return ans;
    }
};