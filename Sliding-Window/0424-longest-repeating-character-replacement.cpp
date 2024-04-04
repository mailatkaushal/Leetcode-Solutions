// Time  : O(2n)
// Space : O(26) ~ O(1)

class Solution {
public:
  int characterReplacement(string& s, int k) {
    int n = s.size();
    int ma = 0;
    vector<int> v(26);
    int maxfreq = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      maxfreq = max(maxfreq, ++v[s[j]-'A']);
      while ((j-i+1) - maxfreq > k) {
        --v[s[i]-'A'];
        ++i;
      }
      ma = max(ma, j-i+1);
    }
    return ma;
  }
};

// Time  : O(n)
// Space : O(26) ~ O(1)

class Solution {
public:
  int characterReplacement(string& s, int k) {
    int n = s.size();
    int ma = 0;
    vector<int> v(26);
    int maxfreq = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      maxfreq = max(maxfreq, ++v[s[j]-'A']);
      if ((j-i+1) - maxfreq > k) {
        --v[s[i]-'A'];
        ++i;
      }
      ma = max(ma, j-i+1);
    }
    return ma;
  }
};