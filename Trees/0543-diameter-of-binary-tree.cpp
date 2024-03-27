// Time  : O(n)
// Space : O(h)

class Solution {
public:
  int ma = 0;
  int height(TreeNode* root) {
    if (root == NULL)
      return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    ma = max(ma, lh+rh);
    return 1 + max(lh, rh);
  }
  int diameterOfBinaryTree(TreeNode* root) {
    height(root);
    return ma;
  }
};