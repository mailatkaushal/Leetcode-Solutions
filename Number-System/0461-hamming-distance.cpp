// Time  : O(32)
// Space : O(1)
class Solution {
public:
  int hammingDistance(int x, int y) {
    // The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
    int a = x ^ y;
    int diff = 0;
    while (a) {
      a = a & (a-1);
      ++diff;
    }
    return diff;
  }
};