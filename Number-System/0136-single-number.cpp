// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int singleNumber(vector<int>& A) {
    int x = 0;
    for (int& a : A) x ^= a;
    return x;
  }
};