// Time  : O(m + n)
// Space : O(m)

class Solution {
public:
  vector<int> intersection(vector<int>& A, vector<int>& B) {
    unordered_set<int> st;
    for (int& a : A)
      st.insert(a);

    vector<int> res;
    for (int& b : B) {
      if (st.find(b) != st.end()) {
        st.erase(b);
        res.push_back(b);
      }
    }

    return res;
  }
};