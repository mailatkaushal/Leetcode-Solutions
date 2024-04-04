// Time  : O(n)
// Space : O(26) ~ O(1)

class Solution {
public:
  int characterReplacement(string s, int k) {
    vector<int> cnt(26, 0);
    int maxCnt = 0, maxLen = 0;

    for (int l = 0, r = 0; r < s.size(); ++r) {
      maxCnt = max(maxCnt, ++cnt[s[r] - 'A']);
      if ((r - l + 1) - maxCnt > k) {  // size of the window - largest count of a single, unique char in the window
        --cnt[s[l] - 'A'];
        ++l;
      }
      maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
  }
};