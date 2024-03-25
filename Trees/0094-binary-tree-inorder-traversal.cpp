// Time  : O(n)
// Space : O(h)

class Solution {
public:
  vector<int> in;
  void inorder(TreeNode*& root) {
    if (root == NULL) 
      return;
    inorder(root->left);
    in.push_back(root->val);
    inorder(root->right);
  }
  vector<int> inorderTraversal(TreeNode* root) {
    inorder(root);
    return in;
  }
};