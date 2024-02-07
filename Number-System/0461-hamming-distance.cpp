// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Time  : O(logn)
// Space : O(1)

class Solution {
public:
  int hammingDistance(int& x, int& y) {
    int res = 0;

    while (x || y) {
      res += (x & 1) ^ (y & 1);
      x >>= 1;
      y >>= 1;
    } 

    return res;
  }
};