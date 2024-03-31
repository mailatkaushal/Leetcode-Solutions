// Time  : O(logn)
// Space : O(1)

class Solution {
public:
  TreeNode* insertIntoBST(TreeNode* root, int x) {
    if (root == NULL) return new TreeNode(x);
    TreeNode* cur = root;
    while (1) {
      if (cur->val < x) {
        if (cur->right) cur = cur->right;
        else {
          cur->right = new TreeNode(x);
          break;
        }
      } 
      else {
        if (cur->left) cur = cur->left;
        else {
          cur->left = new TreeNode(x);
          break;
        }
      }
    }
    return root;
  }
};