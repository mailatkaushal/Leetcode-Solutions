// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1) return -1;
    grid[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    int d = 1;
    while (!q.empty()) {
      int k = q.size();
      while (k--) {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if (x == n-1 && y == n-1) return d;
        for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
              grid[nx][ny] = 1;
              q.push({nx, ny});
            }
          }
        }
      }
      ++d;
    }
    return -1;
  }
};

// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  typedef pair<int, pair<int, int>> P;
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1) return -1;
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<vector<int>> D(n, vector<int> (n, 1e9));
    pq.push({1, {0, 0}});
    D[0][0] = 1;
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int d = p.first;
      int x = p.second.first;
      int y = p.second.second;
      if (x == n-1 && y == n-1) return d;
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          int nx = x + dx;
          int ny = y + dy;
          if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && d + 1 < D[nx][ny]) {
            D[nx][ny] = d + 1;
            pq.push({D[nx][ny], {nx, ny}});
          }
        }
      }
    }
    return -1;
  }
};