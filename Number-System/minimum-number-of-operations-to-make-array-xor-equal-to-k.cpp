// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int minOperations(vector<int>& A, int k) {
    int x = 0;
    for (int& n : A) x ^= n;
    x ^= k;
    int diff = 0;
    while (x) {
      diff += (x & 1);
      x >>= 1;
    }
    return diff;
  }
};