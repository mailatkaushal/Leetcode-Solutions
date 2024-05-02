// Time  : O(n)
// Time  : O(3)
class Solution {
public:
  int numberOfSubstrings(string& s) {
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      mp[s[j]]++;
      while (mp.size() == 3) {
        ans += s.size()-j;
        mp[s[i]]--;
        if (mp[s[i]] == 0) mp.erase(s[i]);
        ++i;
      }
    }
    return ans;
  }
};