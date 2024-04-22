// Time  : O(n)
// Space : O(1)
class Solution {
public:
  TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;
    TreeNode* x = root;
    while (x) {
      if (x->right == NULL) {
        x->val += sum;
        sum = x->val;
        x = x->left;
      }
      else {
        TreeNode* pre = x->right;
        while (pre->left && pre->left != x) pre = pre->left;
        if (pre->left == NULL) {
          pre->left = x;
          x = x->right;
        }
        else {
          pre->left = NULL;
          x->val += sum;
          sum = x->val;
          x = x->left;
        }
      }
    }
    return root;
  }
};