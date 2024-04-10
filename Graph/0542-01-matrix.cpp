// Time  : O(m*n)
// Space : O(m*n)

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& M) {
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int m = M.size();
    int n = M[0].size();
    vector<vector<int>> dist(m, vector<int> (n, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (M[i][j] == 0) {
          dist[i][j] = 0;
          q.push({i, j});
        }
      }
    }
    int d = 0;
    while (!q.empty()) {
      ++d;
      int k = q.size();;
      while (k--) {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for (auto& dir : dirs) {
          int nx = x + dir[0];
          int ny = y + dir[1];
          if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] == -1) {
            dist[nx][ny] = d;
            q.push({nx, ny});
          }
        }
      }
    }
    return dist;
  }
};