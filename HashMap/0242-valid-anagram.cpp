// Time  : O(n) 
// Space : O(26) ~ O(1)

class Solution {
public:
  bool isAnagram(string& s, string& t) {
    if (s.size() != t.size()) 
      return false;
    
    vector<int> cnt(26);

    for (int i = 0; i < s.length(); i++) {
      ++cnt[s[i] - 'a'];
      --cnt[t[i] - 'a'];
    }

    for (int i = 0; i < 26; i++) 
      if (cnt[i] != 0) 
        return false;
        
    return true;
  }
};