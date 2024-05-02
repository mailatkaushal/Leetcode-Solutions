// Time:  O(logn)
// Space: O(1)
class Solution {
public:
  double myPow(double x, int n) {
    long long nn = n;
    if (nn < 0) {
      x = 1/x;
      nn = -nn;
    }
    double ans = 1;
    while (nn) {
      if (nn % 2 == 0) {
        x *= x;
        nn /= 2;
      }
      else {
        ans *= x;
        x *= x;
        nn /= 2;
      }
    }
    return ans;
  }
};