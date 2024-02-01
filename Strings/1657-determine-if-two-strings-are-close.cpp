// Time:  O(n)
// Space: O(1)

class Solution {
public:
  bool closeStrings(string w1, string w2) {
    if (w1.size() != w2.size())
      return false;

    vector<int> v(26, 0), w(26, 0);

    for (int i = 0; i < w1.size(); ++i) {
      ++v[w1[i] - 'a'];
      ++w[w2[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
      if ((v[i] > 0 && w[i] == 0) || (v[i] == 0 && w[i] > 0))
        return false;
    }

    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    return v == w;
  }
};