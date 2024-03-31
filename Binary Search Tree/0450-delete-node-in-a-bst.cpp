// Time  : O(logn)
// Space : O(1)

class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int x) {
    if (root == NULL) return root;
    if (root->val == x) return f(root);
    TreeNode* cur = root;
    while (cur) {
      if (cur->val < x) {
        if (cur->right && cur->right->val == x) {
          cur->right = f(cur->right);
          break;
        }
        else 
          cur = cur->right;
      }
      else {
        if (cur->left && cur->left->val == x) {
          cur->left = f(cur->left);
          break;
        }
        else
          cur = cur->left;
      }
    }
    return root;
  }

  TreeNode* f(TreeNode* root) {
    if (root->right == NULL) return root->left;
    if (root->left == NULL) return root->right;
    TreeNode* rightLeftMost = root->right;
    while (rightLeftMost->left)
      rightLeftMost = rightLeftMost->left;
    rightLeftMost->left = root->left;
    return root->right;
  }
};