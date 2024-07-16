// Time  : O(ElogE)
// Space : O(E)
class Solution {
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s) {
        vector<int> dist(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[s] = 0;
        pq.push({0,s});
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int du = p.first;
            int u = p.second;
            for (auto& it : adj[u]) {
                int v = it[0];
                int duv = it[1];
                if (du + duv < dist[v]) {
                    dist[v] = du + duv;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};
// Time  : O(ElogV)
// Space : O(V)
class Solution {
public:
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s) {
        vector<int> dist(n,1e9);
        set<pair<int,int>> st;
        dist[s] = 0;
        st.insert({0,s});
        while (!st.empty()) {
            auto p = *(st.begin()); st.erase(p);
            int du = p.first;
            int u = p.second;
            for (auto& it : adj[u]) {
                int v = it[0];
                int duv = it[1];
                if (du + duv < dist[v]) {
                    if (dist[v] != 1e9) st.erase({dist[v],v});
                    dist[v] = du + duv;
                    st.insert({dist[v],v});
                }
            }
        }
        return dist;
    }
};