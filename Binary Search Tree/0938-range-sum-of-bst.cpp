// Time  : O(# of nodes in range [lo-hi])
// Space : O(h)
class Solution {
public:
  int rangeSumBST(TreeNode* x, int lo, int hi) {
    if (x == NULL) return 0;
    if (lo <= x->val && x->val <= hi) return x->val + rangeSumBST(x->left, lo, hi) + rangeSumBST(x->right, lo, hi);
    if (x->val < lo) return rangeSumBST(x->right, lo, hi);
    return rangeSumBST(x->left, lo, hi);
  }
};