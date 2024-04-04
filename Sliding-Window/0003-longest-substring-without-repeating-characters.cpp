// Time  : O(2n)
// Space : O(n)

class Solution {
public:
  int lengthOfLongestSubstring(string& s) {
    int n = s.size();
    int ma = 0;
    unordered_set<char> st;
    for (int l = 0, r = 0; r < n; ++r) {
      while (st.find(s[r]) != st.end()) {
        st.erase(s[l]);
        ++l;
      }
      st.insert(s[r]);
      ma = max(ma, r-l+1);
    }
    return ma;
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int lengthOfLongestSubstring(string& s) {
    int n = s.size();
    int ma = 0;
    vector<int> v(256,-1);
    for (int l = 0, r = 0; r < n; ++r) {
      if (v[s[r]] != -1) {
        if (v[s[r]] + 1 > l)
          l = v[s[r]] + 1; 
      } 
      v[s[r]] = r;
      ma = max(ma, r - l + 1);
    }
    return ma;
  }
};