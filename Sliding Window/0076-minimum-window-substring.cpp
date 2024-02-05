// Time  : O(m+n) - where m and n are length of s and t resp.
// Space : O(256) ~ O(1)

class Solution {
public:
  string minWindow(string s, string t) {
    vector<int> cnt(256, 0);
    for (char& c : t)
      ++cnt[c];

    int required_count = t.size();
    int start = -1;
    int min_window = INT_MAX;

    for (int l = 0, r = 0; r < s.size(); ++r) {
      if (cnt[s[r]] > 0) 
        --required_count;

      --cnt[s[r]];

      while (required_count == 0) {
        if (r - l + 1 < min_window) {
          start = l;
          min_window = r - l + 1;
        }

        ++cnt[s[l]];

        if (cnt[s[l]] > 0) 
          ++required_count; 

        ++l;
      }
    }

    return start == -1 ? "" : s.substr(start, min_window);
  }
};