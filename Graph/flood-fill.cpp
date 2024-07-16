class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int m = image.size();
    int n = image[0].size();
    int original = image[sr][sc];
    queue<pair<int,int>> q; q.push({sr, sc});
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      image[x][y] = color;
      for (auto& [dx, dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == original && image[nx][ny] != color) {
          q.push({nx, ny});
        }
      }
    }
    return image;
  }
};