class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans=0;
    unordered_map<char,int> mp;
    for (int i=0,j=0; j<s.size(); ++j) {
      mp[s[j]]++;
      while (mp[s[j]]>1) {
        mp[s[i]]--;
        ++i;
      }
      ans=max(ans,j-i+1);
    }
    return ans;
  }
};