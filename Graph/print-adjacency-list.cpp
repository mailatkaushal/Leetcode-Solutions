// Time  : O(E)
// Space : O(V + 2*E)

class Solution {
public:
  // Function to return the adjacency list for each vertex.
  vector<vector<int>> printGraph(int V, vector<pair<int,int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& e : edges) {
      adj[e.first].push_back(e.second);
      adj[e.second].push_back(e.first);
    }
    return adj;
  }
};