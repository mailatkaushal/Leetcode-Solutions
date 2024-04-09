// Time  : O(2n)
// Space : O(1)

void rotate(vector<vector<int>>& M) {
  int n = M.size();
  int x = 0, y = n-1;
  while (x < y) {
    for (int i = 0; i < n; ++i) 
      swap(M[i][x], M[i][y]);
    ++x, --y;
  }
  for (int i = 0; i < n; ++i) 
    for (int j = i+1; j < n; ++j) 
      swap(M[i][j], M[j][i]);
}