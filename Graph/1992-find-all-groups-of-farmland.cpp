// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    vector<vector<int>> dirs = {{0,1},{1,0}};
    vector<vector<int>> ans;
    int m = land.size();
    int n = land[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (land[i][j] == 1) {
          land[i][j] = 0;
          queue<pair<int, int>> q;
          q.push({i, j});
          int x, y;
          while (!q.empty()) {
            auto p = q.front();
            q.pop();
            x = p.first;
            y = p.second;
            for (auto& dir : dirs) {
              int nx = x + dir[0];
              int ny = y + dir[1];
              if (nx >= 0 && nx < m && ny >= 0 && ny < n && land[nx][ny] == 1) {
                land[nx][ny] = 0;
                q.push({nx, ny});
              } 
            }
          }
          ans.push_back({i, j, x, y});
        }
      }
    }
    return ans;
  }
};