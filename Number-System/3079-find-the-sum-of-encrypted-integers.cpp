// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int sumOfEncryptedInt(vector<int>& A) {
    int ans = 0;
    for (int& a : A) {
      int digits = 0;
      int maxdigit = 1;
      while (a) {
        int digit = a % 10;
        ++digits;
        maxdigit = max(maxdigit, digit);
        a /= 10;
      }
      int aa = 0;
      while (digits--) {
        aa = aa * 10 + maxdigit;
      }
      ans += aa;
    }
    return ans;
  }
};