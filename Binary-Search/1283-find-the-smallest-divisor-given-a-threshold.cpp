// Time  : O(nlogm)
// Space : O(1)
class Solution {
public:
  int smallestDivisor(vector<int>& A, int threshold) {
    int lo = 1;
    int hi = *max_element(A.begin(), A.end());
    while (lo < hi) {
      int d = (lo + hi)>>1;
      long long sum = 0;
      for (int& a : A) sum += ceil(1.0 * a / d);
      if (sum > threshold) lo = d+1;
      else hi = d;
    }
    return lo;
  }
};