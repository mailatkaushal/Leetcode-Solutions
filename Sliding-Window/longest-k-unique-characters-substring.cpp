// Time  : O(2n)
// Space : O(k)

class Solution {
public:
  int longestKSubstr(string& s, int k) {
    int n = s.size();
    int ma = -1;
    unordered_map<int, int> ump;
    for (int i = 0, j = 0; j < n; ++j) {
      ++ump[s[j]];
      while (ump.size() > k) {
        --ump[s[i]];
        if (ump[s[i]] == 0) ump.erase(s[i]);
        ++i;
      }
      if (ump.size() == k) ma = max(ma, j-i+1);
    }
    return ma;
  }
};

// Time  : O(n)
// Space : O(k)

class Solution {
public:
  int longestKSubstr(string& s, int k) {
    int n = s.size();
    int ma = -1;
    unordered_map<int, int> ump;
    for (int i = 0, j = 0; j < n; ++j) {
      ++ump[s[j]];
      while (ump.size() > k) {
        --ump[s[i]];
        if (ump[s[i]] == 0) ump.erase(s[i]);
        ++i;
      }
      if (ump.size() == k) ma = max(ma, j-i+1);
    }
    return ma;
  }
};