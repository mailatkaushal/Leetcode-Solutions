// Time  : O(logx)
// Space : O(1)
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    long long y = x;
    long long z = 0;
    while (y) {
      int d = y % 10;
      z = z * 10 + d;
      y /= 10;
    }
    return x == z;
  }
};