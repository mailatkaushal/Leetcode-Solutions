// Time  : O(logn)
// Space : O(1)

class Solution:
  def isPowerOfTwo(self, n: int) -> bool:
    x = 1
    while x < n:
      x *= 2
    return x == n

// Time  : O(logn)
// Space : O(1)

class Solution {
public:
  bool isPowerOfTwo(int n) {
    int sum_bits = 0;

    while (n > 0) {
      int bit = n & 1;
      sum_bits += bit;
      n = n >> 1;
    }

    return sum_bits == 1;
  }
};

// Time  : O(1)
// Space : O(1)

class Solution:
  def isPowerOfTwo(self, n: int) -> bool:
    if n <= 0:
      return False

    return n & (n - 1) == 0