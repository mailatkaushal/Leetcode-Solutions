// Time  : O(m*n) - m -> number of words, n -> maximum length of word
// Space : O(1)

class Solution {
public:
  string firstPalindrome(vector<string>& words) {
    for (string& w : words) {
      int n = w.size();
      if (equal(w.begin(), w.begin() + n/2, w.rbegin()))
        return w;
    }

    return "";
  }
};