// Time  : O(n)
// Space : O(26) ~ O(1)

class Solution {
public:
  string lastNonEmptyString(string s) {
    vector<int> v(26);
    int max_freq = 0;

    for (char& c : s) 
      max_freq = max(max_freq, ++v[c - 'a']);

    string res;

    for (int i = s.size() - 1; i >= 0; --i) {
      if (v[s[i] - 'a'] == max_freq) {
        res = s[i] + res;
        --v[s[i] - 'a'];
      } 
    }

    return res;
  }
};