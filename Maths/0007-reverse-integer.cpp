// Time  : O(logx)
// Space : O(1)
class Solution {
public:
  int reverse(int x) {
    long long y = x;
    long long z = 0;
    while (y) {
      int d = y % 10;
      z = z * 10 + d;
      y /= 10;
    }
    if (z < INT_MIN || z > INT_MAX) return 0;
    return z;
  }
};