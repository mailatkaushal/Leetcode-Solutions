// Time  : O(n^2)
// Space : O(1)
class Solution {
public:
  void rotate(vector<vector<int>>& M) {
    int m = M.size();
    int n = M[0].size();
    for (int i=0; i<m; ++i) {
      for (int j=0; j<i; ++j) {
        swap(M[i][j], M[j][i]);
      }
    }
    for (int i=0; i<m; ++i) {
      int x = 0, y = n-1;
      while (x < y) swap(M[i][x++], M[i][y--]);
    }
  }
};