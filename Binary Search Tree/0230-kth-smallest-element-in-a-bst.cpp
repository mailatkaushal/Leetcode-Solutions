// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int kthSmallest(TreeNode* x, int k) {
    int i = 0;
    int ans;
    while (x) {
      if (x->left == NULL) {
        if (++i == k) { ans = x->val; break; }
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