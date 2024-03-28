// Time  : O(n)
// Space : O(h)

class Solution {
public:
  int max_path = INT_MIN;
  int f(TreeNode* root) {
    if (root == NULL)
      return 0;
    int gain_from_left = max(0, f(root->left));
    int gain_from_right = max(0, f(root->right));
    max_path = max(max_path, root->val + gain_from_left + gain_from_right);
    return root->val + max(gain_from_left, gain_from_right);
  }
  int maxPathSum(TreeNode* root) {
    f(root);
    return max_path;
  }
};