// Time  : O(m*n)
// Space : O(m*n)

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor) {
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int m = image.size();
    int n = image[0].size();
    int initialColor = image[sr][sc];
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      image[x][y] = newColor;
      for (auto& dir : dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == initialColor && image[nx][ny] != newColor) 
          q.push({nx, ny});
      }
    }
    return image;
  }
};