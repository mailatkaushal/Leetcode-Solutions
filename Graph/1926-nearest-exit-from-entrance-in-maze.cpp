// Time  : O(m*n)
// Space : O(m*n)
class Solution {
public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int m = maze.size();
    int n = maze[0].size();
    maze[entrance[0]][entrance[1]] = '+';
    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});
    int ans = 1;
    while (!q.empty()) {
      int z = q.size();
      while (z--) {
        auto [x, y] = q.front();
        q.pop();
        for (auto& dir : dirs) {
          int nx = x + dir[0];
          int ny = y + dir[1];
          if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
            if (nx == 0 || nx == m-1 || ny == 0 || ny == n-1) return ans;
            maze[nx][ny] = '+';
            q.push({nx, ny});
          }
        }
      }
      ++ans;
    }
    return -1;
  }
};