void shortest_distance(vector<vector<int>>& M){
      int n = M.size();
      for (int i=0; i<n; ++i) {
          for (int j=0; j<n; ++j) {
              if (M[i][j] == -1) M[i][j] = 1e9;
          }
      }
      for (int k=0; k<n; ++k) {
          for (int i=0; i<n; ++i) {
              for(int j=0; j<n; ++j) {
                  M[i][j] = min(M[i][j], M[i][k]+M[k][j]);
              }
          }
      }
      for (int i=0; i<n; ++i) {
          for (int j=0; j<n; ++j) {
              if (M[i][j] == 1e9) M[i][j] = -1;
          }
      }
}