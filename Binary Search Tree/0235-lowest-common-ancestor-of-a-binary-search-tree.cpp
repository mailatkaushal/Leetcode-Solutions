// Time  : O(logn)
// Space : O(logn)

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* x, TreeNode* y) {
    if (root == NULL || root == x || root == y) return root;
    if (root->val < x->val && root->val < y->val) return lowestCommonAncestor(root->right, x, y);
    if (root->val > x->val && root->val > y->val) return lowestCommonAncestor(root->left, x, y);
    return root;
  }
};

// Time  : O(logn)
// Space : O(1)

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* x, TreeNode* y) {
    while (root) {
      if (root->val < x->val && root->val < y->val) root = root->right;
      else if (root->val > x->val && root->val > y->val) root = root->left;
      else break;
    }
    return root;
  }
};