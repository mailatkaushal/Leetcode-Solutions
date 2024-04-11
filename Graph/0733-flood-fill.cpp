// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
  vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    int ini = image[sr][sc];
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int x = p.first;
      int y = p.second;
      image[x][y] = color;
      for (auto& dir : dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == ini && image[nx][ny] != color) 
          q.push({nx, ny});
      }
    }
    return image;
  }
};