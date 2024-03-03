// Time  : O(n)
// Space : O(h)

class Solution {
public:
  bool f(TreeNode* root, int k) {
    if (!root)
      return false;
    if (!root->left && !root->right) 
      return k - root->val == 0;

    return f(root->left, k - root->val) || f(root->right, k - root->val);
  }

  bool hasPathSum(TreeNode* root, int targetSum) {
    return f(root, targetSum);
  }
};