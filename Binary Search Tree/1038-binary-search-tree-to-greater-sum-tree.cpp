// Time  : O(n)
// Space : O(1)
class Solution {
public:
  TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;
    TreeNode* x = root;
    while (x) {
      if (x->right == NULL) {
        sum += x->val;
        x->val = sum;
        x = x->left;
      }
      else {
        TreeNode* y = x->right;
        while (y->left && y->left != x) y = y->left;
        if (y->left == NULL) {
          y->left = x;
          x = x->right;
        }
        else {
          y->left = NULL;
          sum += x->val;
          x->val = sum;
          x = x->left;
        }
      }
    }
    return root;
  }
};