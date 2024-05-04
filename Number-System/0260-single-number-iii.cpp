// Time  : O(n)
// Space : O(1)
class Solution {
public:
  vector<int> singleNumber(vector<int>& A) {
    long long xo = 0;
    for (int& a : A) xo ^= a;
    xo = (xo & (xo - 1)) ^ xo;
    int p = 0;
    int q = 0;
    for (int& a : A) {
      if (a & xo) p ^= a;
      else q ^= a;
    }
    return {p, q};
  }
};