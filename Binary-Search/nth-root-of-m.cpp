# Time  : O(logn)
# Space : O(1)

int f(int& mid, int& n, int& m) {
  long long res = 1;
  for (int i = 1; i <= n; ++i) {
    res *= mid;
    if (res > m)
      return 2;
  }
  if (res == m)
    return 1;
  return 0;
}

int NthRoot(int n, int m) {
  int lo = 1, hi = m;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    int midN = f(mid, n, m);
    if (midN == 0)
      lo = mid + 1;
    else if (midN == 2)
      hi = mid - 1;
    else
      return mid;
  }
  return -1;
}