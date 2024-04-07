// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int atoi(string s) {
    int n = s.size();
    int res = 0;
    bool neg = false;
    for (int i = 0; i < n; ++i) {
      if (i == 0 && s[i] == '-') 
        neg = true;
      else if (s[i] >= '0' && s[i] <= '9')
        res = res * 10 + (s[i] - '0');
      else 
        return -1;
    }
    return (neg == true) ? -res : res;
  }
};