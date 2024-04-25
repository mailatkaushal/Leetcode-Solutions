// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int firstElement(int n) {
    int a = 1;
    int b = 1;
    for (int i = 2; i < n; ++i) {
      int sum = (a + b) % 1000000007;
      a = b;
      b = sum;
    }
    return b;
  }
};