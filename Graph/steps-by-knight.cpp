// Time  : O(n^2)
// Space : O(n^2)
class Solution {
public:
  //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
    vector<vector<int>> dirs = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
    vector<vector<int>> grid(N, vector<int> (N, 1));
    grid[KnightPos[0]-1][KnightPos[1]-1] = 0;
    queue<pair<int, int>> q;
    q.push({KnightPos[0]-1, KnightPos[1]-1});
    int ans = 0;
    while (!q.empty()) {
      int k = q.size();
      while (k--) {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if (x == TargetPos[0]-1 && y == TargetPos[1]-1) return ans;
        for (auto& dir : dirs) {
          int nx = x + dir[0];
          int ny = y + dir[1];
          if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] == 1) {
            grid[nx][ny] = 0;
            q.push({nx, ny});
          }
        }
      }
      ++ans;
    }
    return -1;
	}
};