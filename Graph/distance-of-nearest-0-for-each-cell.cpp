class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& M) {
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int m = M.size();
    int n = M[0].size();
    vector<vector<bool>> vis(m,vector<bool>(n));
    queue<pair<int,int>> q;
    for (int i=0; i<m; ++i) {
      for (int j=0; j<n; ++j) {
        if (M[i][j] == 0) { vis[i][j] = 1; q.push({i,j}); }
      }
    }
    int d = 1;
    while (!q.empty()) {
      int z = q.size();
      while (z--) {
        auto [x,y] = q.front(); q.pop();
        for (auto& [dx,dy] : dirs) {
          int nx = x + dx;
          int ny = y + dy;
          if (nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny] == 0) {
            M[nx][ny] = d;
            vis[nx][ny] = 1;
            q.push({nx,ny});
          }
        }
      }
      d++;
    }
    return M;
  }
};