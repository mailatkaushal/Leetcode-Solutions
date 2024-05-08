// Time  : O(logn)
// Space : O(1)
class Solution {
public:
  TreeNode* del(TreeNode* d) {
    if (d->left == NULL) return d->right;
    if (d->right == NULL) return d->left;
    TreeNode* x = d->right;
    while (x->left) x = x->left;
    x->left = d->left;
    return d->right;
  }
  TreeNode* deleteNode(TreeNode* root, int x) {
    if (root == NULL) return NULL;
    if (root->val == x) return del(root);
    TreeNode* cur = root;
    while (cur) {
      if (cur->val < x) {
        if (cur->right && cur->right->val == x) { cur->right = del(cur->right); break; }
        cur = cur->right;
      }
      else {
        if (cur->left && cur->left->val == x) { cur->left = del(cur->left); break; }
        cur = cur->left;
      }
    }
    return root;
  }
};