// Time  : O(N*M + k^2)
// Space : O(k^2)
class Solution{
  public:
  string findOrder(string dict[], int N, int k) {
    vector<vector<int>> adj(k);
    vector<int> indeg(k);
    for (int i = 0; i < N-1; ++i) {
      for (int x = 0; x < min(dict[i].size(), dict[i+1].size()); ++x) {
        if (dict[i][x] != dict[i+1][x]) {
          adj[dict[i][x] - 'a'].push_back(dict[i+1][x] - 'a');
          ++indeg[dict[i+1][x] - 'a'];
          break;
        }
      }
    }
    queue<int> q;
    for (int i = 0; i < k; ++i) {
      if (indeg[i] == 0) {
        q.push(i);
      }
    }
    string ret;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ret += u + 'a';
      for (int& v : adj[u]) {
        --indeg[v];
        if (indeg[v] == 0) q.push(v);
      }
    }
    return ret;
  }
};