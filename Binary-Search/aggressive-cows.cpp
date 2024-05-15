// Time  : O(nlogn + nlogm) - Where n is len(stalls), m is max(stalls) - min(stalls)
// Space : O(logn) - bc of sorting
class Solution {
public:
  int solve(int n, int k, vector<int>& A) {
    sort(A.begin(), A.end());
    int lo = 1;
    int hi = A[n-1] - A[0];
    while (lo <= hi) {
      int dist = (lo + hi)>>1;
      bool canPlace = false;
      int c = 1;
      int x = A[0];
      for (int i = 1; i < n; ++i) {
        if (A[i] - x >= dist) {
          c++;
          if (c == k) {
            canPlace = true;
            break;
          }
          x = A[i];
        }
      }
      if (canPlace) lo = dist+1;
      else hi = dist-1;
    }
    return hi;
  }
};