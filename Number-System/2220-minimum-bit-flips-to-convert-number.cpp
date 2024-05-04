// Time  : O(32)
// Space : O(1)
class Solution {
public:
  int minBitFlips(int start, int goal) {
    int x = start ^ goal;
    int diff = 0;
    while (x) {
      x = x & (x - 1);
      ++diff;
    }
    return diff;
  }
};