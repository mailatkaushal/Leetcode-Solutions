// Time  : O(n)
// Space : O(k)
int getLengthofLongestSubstring(int k, string& s) {
  int ans = 0;
  unordered_map<int, int> mp;
  for (int i = 0, j = 0; j < s.size(); ++j) {
    mp[s[j]]++;
    if (mp.size() > k) {
      mp[s[i]]--;
      if (mp[s[i]] == 0) mp.erase(s[i]);
      ++i;
    }
    ans = max(ans, j-i+1);
  }
  return ans;
}