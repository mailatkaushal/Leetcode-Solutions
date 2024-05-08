// Time  : O(logn)
// Space : O(1)
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* x, TreeNode* a, TreeNode* b) {
    while (x) {
      if (x->val < a->val && x->val < b->val) x = x->right;
      else if (x->val > a->val && x->val > b->val) x = x->left;
      else break;
    }
    return x;
  }
};