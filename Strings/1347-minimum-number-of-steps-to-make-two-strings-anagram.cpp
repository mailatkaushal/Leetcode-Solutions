// Time: O(n)
// Space: O(1)

class Solution {
public:
  int minSteps(string& s, string& t) {
    vector<int> v(26, 0);
    for (char& c: s) 
      v[c - 'a']++;
    
    int res = 0;

    for (char& c: t) {
      if (v[c - 'a'] > 0) {
        v[c - 'a']--;
        continue;
      }
      res++;
    }

    return res;
  }
};