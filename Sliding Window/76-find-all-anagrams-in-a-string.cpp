// Time  : O(n)
// Space : O(1)

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> cnt(26);
    for (char& c : p) 
      ++cnt[c - 'a'];

    int window_size = p.size();
    vector<int> res;

    for (int l = 0, r = 0; r < s.size(); ++r) {
      --cnt[s[r] - 'a'];
      if (r - l + 1 == window_size) {
        if (cnt == vector<int> (26)) {
          res.push_back(l);
        }
        ++cnt[s[l] - 'a'];
        l++;
      }
    }

    return res;
  }
};