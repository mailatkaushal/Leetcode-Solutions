// Time  : O(n)
// Space : O(n)
class Solution {
public:
  void findPaths(TreeNode* x, string a, vector<string>& ans) {
    if (x == NULL) return;
    a += "->" + to_string(x->val);
    if (x->left == NULL && x->right == NULL) {
      ans.push_back(a);
      return;
    }
    findPaths(x->left, a, ans);
    findPaths(x->right, a, ans);
  }
  vector<string> binaryTreePaths(TreeNode* root) {
    if (root->left == NULL && root->right == NULL) return {to_string(root->val)};
    vector<string> ans;
    findPaths(root->left, to_string(root->val), ans);
    findPaths(root->right, to_string(root->val), ans);
    return ans;
  }
};