// Time  : O(|order| + |s|)
// Space : O(26) ~ O(1)

class Solution {
public:
  string customSortString(string order, string s) {
    vector<int> cnt(26);
    for (char& c : s)
      ++cnt[c - 'a'];

    string res;
    for (char& c : order) {
      while (cnt[c - 'a']--) 
        res += c;
    }

    // Adding the chars which are not present in order
    for (char c = 'a'; c <= 'z'; ++c) {
      while (cnt[c - 'a']-- > 0) 
        res += c;
    }

    return res;
  }
};