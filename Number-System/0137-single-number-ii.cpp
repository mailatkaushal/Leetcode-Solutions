// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int singleNumber(vector<int>& A) {
    int ones = 0;
    int twos = 0;
    for (int& a : A) {
      ones = (ones ^ a) & (~twos);
      twos = (twos ^ a) & (~ones);
    }
    return ones;
  }
};