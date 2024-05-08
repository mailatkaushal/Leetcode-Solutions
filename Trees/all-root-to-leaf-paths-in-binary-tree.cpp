// Time  : O(n)
// Space : O(n/2*logn)
class Solution {
public:
  void findPaths(Node* x, vector<int>& a, vector<vector<int>>& ans) {
    if (x == NULL) return;
    a.push_back(x->data);
    if (x->left == NULL && x->right == NULL) ans.push_back(a);
    findPaths(x->left, a, ans);
    findPaths(x->right, a, ans);
    a.pop_back();
  } 
  vector<vector<int>> Paths(Node* x) {
    vector<vector<int>> ans;
    vector<int> a;
    findPaths(x, a, ans);
    return ans;
  }
};