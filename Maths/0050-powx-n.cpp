// Time:  O(logn)
// Space: O(1)

class Solution {
public:
  double myPow(double x, int n) {
    double res = 1;
    long long exp = n;

    if (exp < 0) {
      x = 1 / x;
      exp = -exp;
    }

    while (exp) {
      if (exp % 2 == 1)
        res *= x;
      x *= x;
      exp >>= 1;
    }

    return res;
  }
};