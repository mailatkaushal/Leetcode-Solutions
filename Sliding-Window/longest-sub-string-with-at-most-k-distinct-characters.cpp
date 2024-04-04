// Time  : O(n)
// Space : O(k)

int getLengthofLongestSubstring(int k, string& s) {
  int n = s.size();
  int ma = 0;
  unordered_map<int, int> ump;
  for (int i = 0, j = 0; j < n; ++j) {
  ++ump[s[j]];
  while (ump.size() > k) {
    --ump[s[i]];
    if (ump[s[i]] == 0) ump.erase(s[i]);
    ++i;
  }
  ma = max(ma, j-i+1);
  }
  return ma;
}