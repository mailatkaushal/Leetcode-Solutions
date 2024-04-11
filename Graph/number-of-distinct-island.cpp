// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
  int countDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    unordered_set<string> st;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          grid[i][j] = 0;
          q.push({i, j});
          string s;
          while (!q.empty()) {
            int k = q.size();
            while (k--) {
              auto p = q.front();
              q.pop();
              int x = p.first;
              int y = p.second;
              if (s.size()) s += '_';
              s += to_string(x - i) + '_' + to_string(y - j);
              for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && nx <= m-1 && ny >= 0 && ny <= n-1 && grid[nx][ny] == 1) {
                  grid[nx][ny] = 0;
                  q.push({nx, ny});
                }
              }
            }
          }
          st.insert(s);
        }
      }
    }
    return st.size();
  }
};