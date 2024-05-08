// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int getMinimumDifference(TreeNode* x) {
    int ans = 1e5;
    int p = -1;
    while (x) {
      if (x->left == NULL) {
        if (p != -1) ans = min(ans, x->val - p);
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
    return ans;
  }
};