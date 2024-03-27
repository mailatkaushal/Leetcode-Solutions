// Time  : O(n^2)
// Space : O(n)

class Solution {
public:
  int height(TreeNode* root) {
    if (root == NULL)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }
  bool isBalanced(TreeNode* root) {
    if (root == NULL)
      return true;
    bool lBal = isBalanced(root->left);
    if (lBal == false)
      return false;
    bool rBal = isBalanced(root->right);
    if (rBal == false)
      return false;
    int lh = height(root->left);
    int rh = height(root->right);
    return abs(lh - rh) <= 1;
  }
};