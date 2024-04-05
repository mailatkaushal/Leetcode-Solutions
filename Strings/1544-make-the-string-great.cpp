// Time  : O(n)
// Space : O(1)

class Solution {
public:
  string makeGood(string& s) {
    // a - A = 97 - 65 = 32
    string ret;
    for (int i = 0; i < s.size(); ++i) {
      if (ret.size() && (ret.back() + 32 == s[i] || ret.back() - 32 == s[i])) 
        ret.pop_back();
      else 
        ret += s[i];
    }
    return ret;
  }
};