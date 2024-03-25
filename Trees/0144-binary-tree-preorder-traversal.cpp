// Time  : O(n)
// Space : O(h)

class Solution {
public:
  vector<int> pre;
  void preorder(TreeNode* root) {
    if (root == NULL)
      return;
    pre.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
  }
  vector<int> preorderTraversal(TreeNode* root) {
    preorder(root);
    return pre;
  }
};