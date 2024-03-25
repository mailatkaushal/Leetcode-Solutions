// Time  : O(logx)
// Space : O(1)

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 10)
      return false;
    long long rev = 0;
    long long num = x;
    while (num) {
      int digit = num % 10;
      rev = rev * 10 + digit;
      num /= 10;
    }
    return x == rev;
  }
};