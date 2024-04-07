// Time  : O(n)
// Space : O(n)

class Solution{
public:
  bool subArrayExists(int A[], int n) {
    unordered_set<int> st;
    st.insert(0);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += A[i];
      if (st.find(sum) != st.end()) return true;
      st.insert(sum);
    }
    return false;
  }
};