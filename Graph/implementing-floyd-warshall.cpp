// Time  : O(n^3)
// Space : O(1)
class Solution {
public:
void shortest_distance(vector<vector<int>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == -1) mat[i][j] = 1e9;
      }
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1e9) mat[i][j] = -1;
      }
    }
  }
};