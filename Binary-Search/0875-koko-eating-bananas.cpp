// Time  : O(nlogm)
// Space : O(1)
class Solution {
public:
  int minEatingSpeed(vector<int>& A, int h) {
    int lo = 1;
    int hi = *max_element(A.begin(), A.end());
    while (lo < hi) {
      int k = (lo + hi)>>1;
      long long hours = 0;
      for (int& a : A) hours += ceil(1.0 * a / k);
      if (hours > h) lo = k+1;
      else hi = k;
    }
    return lo;
  }
};