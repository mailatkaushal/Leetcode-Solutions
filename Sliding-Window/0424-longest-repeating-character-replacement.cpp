// Time  : O(n)
// Space : O(26)
class Solution {
public:
  int characterReplacement(string& s, int k) {
    int ans = 0;
    vector<int> v(26);
    int maxFreq = 0;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      maxFreq = max(maxFreq, ++v[s[j] - 'A']);
      if ((j-i+1) - maxFreq > k) {
        --v[s[i] - 'A'];
        ++i;
      }
      ans = max(ans, j-i+1);
    }
    return ans;
  }
};