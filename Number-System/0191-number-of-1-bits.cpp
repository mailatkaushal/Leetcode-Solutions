// Time  : O(32) ~ O(1)
// Space : O(1)

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int cnt = 0;

    while (n) {
      cnt += (n & 1);  // cnt += n % 2
      n >>= 1;         // n /= 2
    }

    return cnt;
  }
};

// Time  : O(k) - where k is number of set bits in n
// Space : O(1)

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int cnt = 0;

    while (n) {
      n = n & (n - 1);
      ++cnt;
    }

    return cnt;
  }
};