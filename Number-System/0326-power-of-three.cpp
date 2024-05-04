// Time  : O(1)
// Space : O(1)
class Solution {
public:
  bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;  // 3^19 = 1162261467
  }
};