// Time  : O(n)
// Space : O(n)

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    vector<int> v1(128,-1);
    vector<int> v2(128,-1);
    for (int i = 0; i < s.size(); ++i) {
      if (v1[s[i]] != -1 && v1[s[i]] != t[i] || v2[t[i]] != -1 && v2[t[i]] != s[i]) 
        return false;
      v1[s[i]] = t[i];
      v2[t[i]] = s[i];
    }
    return true;
  }
};