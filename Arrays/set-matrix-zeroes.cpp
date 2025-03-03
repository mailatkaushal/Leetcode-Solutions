class Solution {
public:
  void setZeroes(vector<vector<int>>& M) {
    int m = M.size();
    int n = M[0].size();
    bool col0 = 1;
    for (int i=0; i<m; ++i) {
      for(int j=0; j<n; ++j) {
        if (M[i][j] == 0) {
          M[i][0] = 0;
          if (j == 0) col0 = 0;
          else M[0][j] = 0;
        }
      }
    }
    for (int i=1; i<m; ++i) {
      for (int j=1; j<n; ++j) {
        if (M[i][0] == 0 || M[0][j] == 0) {
          M[i][j] = 0;
        }
      }
    }
    if (M[0][0] == 0) for (int j=0; j<n; ++j) M[0][j] = 0;
    if (col0 == 0) for (int i=0; i<m; ++i) M[i][0] = 0;
  }
};