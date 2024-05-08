// Time  : O(logn)
// Space : O(1)
class Solution {
public:
  TreeNode* searchBST(TreeNode* root, int x) {
    while (root) {
      if (root->val == x) break;
      if (root->val < x) root = root->right;
      else root = root->left;
    }
    return root;
  }
};