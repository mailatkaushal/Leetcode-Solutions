// Time  : O(n)
// Space : O(1)
class Solution {
public:
  bool isValidBST(TreeNode* x) {
    long long p = LLONG_MIN;
    while (x) {
      if (x->left == NULL) {
        if (p >= x->val) return false;
        p = x->val;
        x = x->right;
      }
      else {
        TreeNode* y = x->left;
        while (y->right) y = y->right;
        y->right = x;
        TreeNode* z = x;
        x = x->left;
        z->left = NULL;
      }
    }
    return true;
  }
};