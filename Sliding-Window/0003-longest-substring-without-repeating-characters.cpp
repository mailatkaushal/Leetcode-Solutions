// Time  : O(n)
// Space : O(n)
class Solution {
public:
  int lengthOfLongestSubstring(string& s) {
    int ans = 0;
    vector<int> v(256, -1);
    for (int i = 0, j = 0; j < s.size(); ++j) {
      if (v[s[j]] != -1) {
        i = max(i, v[s[j]] + 1);
      }
      v[s[j]] = j;
      ans = max(ans, j-i+1);
    }
    return ans;
  }
};