// Time  : O(2^n)
// Space : O(n*2^n)
class Solution {
public:
  void dfs(vector<int>& A, int i, vector<int>& a, vector<vector<int>>& ans) {
    if (i == A.size()) {
      ans.push_back(a);
      return;
    }
    dfs(A, i+1, a, ans);
    a.push_back(A[i]);
    dfs(A, i+1, a, ans);
    a.pop_back();
  }
  vector<vector<int>> subsets(vector<int>& A) {
    vector<vector<int>> ans;
    vector<int> a;
    dfs(A, 0, a, ans);
    return ans;
  }
};

// Time  : O(2^n)
// Space : O(n*2^n)
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& A) {
    int n = A.size();
    int cnt = 1 << n;
    vector<vector<int>> ans(cnt);
    for (int i = 0; i < cnt; ++i) {
      vector<int> a;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1 == 1) a.push_back(A[j]);
      }
      ans[i] = a;
    }
    return ans;
  }
};