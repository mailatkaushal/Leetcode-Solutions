// Time  : O(mlogn)
// Space : O(1)

int rowWithMax1s(vector<vector<int>>& M, int m, int n) {
  int index = -1;
  int cnt_max = 0;
  for (int i = 0; i < m; ++i) {
    int lo = 0, hi = n;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (M[i][mid] == 0) 
        lo = mid + 1;
      else
        hi = mid;
    }
    if (n - lo > cnt_max) {
      cnt_max = n - lo;
      index = i;
    }
  }
  return index;
}