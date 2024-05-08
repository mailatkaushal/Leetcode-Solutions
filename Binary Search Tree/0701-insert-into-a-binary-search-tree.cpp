// Time  : O(logn)
// Space : O(1)
class Solution {
public:
  TreeNode* insertIntoBST(TreeNode* root, int x) {
    if (root == NULL) return new TreeNode(x);
    TreeNode* cur = root;
    while (cur) {
      if (cur->val < x) {
        if (cur->right == NULL) {
          cur->right = new TreeNode(x);
          break;
        }
        cur = cur->right;
      }
      else {
        if (cur->left == NULL) {
          cur->left = new TreeNode(x);
          break;
        }
        cur = cur->left;
      }
    }
    return root;
  }
};