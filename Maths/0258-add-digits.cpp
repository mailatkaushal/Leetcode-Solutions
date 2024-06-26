// Time  : O(logn)
// Space : O(1)

class Solution {
public:
  int addDigits(int num) {
    while (num / 10) {
      int sum = 0;
      while (num) {
        sum += num % 10;
        num /= 10;
      }
      num = sum;
    }
    return num;
  }
};