// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  typedef pair<int, pair<int, int>> P;
  vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
  int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<vector<int>> E(m, vector<int> (n, 1e9));
    pq.push({0, {0, 0}});
    E[0][0] = 0;
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int e = p.first;
      int x = p.second.first;
      int y = p.second.second;
      if (x == m-1 && y == n-1) return e;
      for (auto& dir : dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && max(e, abs(heights[x][y] - heights[nx][ny])) < E[nx][ny]) {
          E[nx][ny] = max(e, abs(heights[x][y] - heights[nx][ny]));
          pq.push({E[nx][ny], {nx, ny}});
        }
      }
    }
    return 0;
  }
};