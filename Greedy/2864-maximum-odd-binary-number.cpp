// Time  : O(n)
// Space : O(1)

class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    // largest number -> move all the 1's at start 
    // odd number -> put 1 at last index

    int n = s.size();
    int cnt_1 = 0;
    for (char& c : s) {
      if (c == '1')
        ++cnt_1;
    }

    string res = string(n, '0');
    for (int i = 0; cnt_1 > 1; ++i) {
      res[i] = '1';
      cnt_1--;
    }
    res[n-1] = '1';

    return res;
  }
};