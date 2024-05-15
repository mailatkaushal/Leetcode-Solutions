// Time  : O(nlogm)
// Space : O(1)
class Solution {
public:
  int shipWithinDays(vector<int>& weights, int days) {
    int mx = 0;
    int sum = 0;
    for (int& w : weights) {
      mx = max(mx, w);
      sum += w;
    }
    int lo = mx;
    int hi = sum;
    while (lo < hi) {
      int cap = (lo + hi)>>1;
      int d = 1;
      long long load = 0;
      for (int& w : weights) {
        if (load + w <= cap) load += w;
        else {
          d += 1;
          load = w;
        }
      }
      if (d > days) lo = cap+1;
      else hi = cap;
    }
    return lo;
  }
};