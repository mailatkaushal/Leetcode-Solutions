// Time  : O(max(m, n))
// Space : O(1)

class Solution {
public:
  string addStrings(string a, string b) {
    string c;
    int m = a.size(), n = b.size();
    int i = m-1, j = n-1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
      int sum = carry;
      if (i >= 0) {
        sum += a[i] - '0';
        --i;
      }
      if (j >= 0) {
        sum += b[j] - '0';
        --j;
      }
      c += (sum % 10) + '0';
      carry = sum / 10;
    }
    reverse(c.begin(), c.end());
    return c;
  }
};