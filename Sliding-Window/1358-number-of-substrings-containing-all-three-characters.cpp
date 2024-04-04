// Time  : O(n)
// Time  : O(3) ~ O(1)

class Solution {
public:
  int numberOfSubstrings(string& s) {
    int n = s.size();
    int cnt = 0;
    unordered_map<char, int> ump;
    for (int i = 0, j = 0; j < n; ++j) {
      ++ump[s[j]];
      while (ump.size() == 3) {
        cnt += n-j;
        --ump[s[i]];
        if (ump[s[i]] == 0) ump.erase(s[i]);
        ++i;
      }
    }
    return cnt;
  }
};