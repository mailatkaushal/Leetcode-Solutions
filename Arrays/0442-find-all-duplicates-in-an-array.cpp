// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> findDuplicates(vector<int>& A) {
    unordered_set<int> st;
    vector<int> res;
    for (int& a : A) {
      if (st.find(a) != st.end()) {
        res.push_back(a);
        continue;
      }
      st.insert(a);
    }
    return res;
  }
};

// Time  : O(n)
// Space : O(1)

class Solution {
public:
  vector<int> findDuplicates(vector<int>& A) {
    int n = A.size();
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      int num = abs(A[i]);
      if (A[num - 1] < 0) 
        res.push_back(num);
      else 
        A[num-1] = -A[num-1];
    }
    return res;
  }
};