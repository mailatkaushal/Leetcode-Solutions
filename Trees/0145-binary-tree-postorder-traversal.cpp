// Time  : O(n)
// Space : O(h)

class Solution {
public:
  vector<int> post;
  void postorder(TreeNode* root) {
    if (root == NULL)
      return;
    postorder(root->left);
    postorder(root->right);
    post.push_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode* root) {
    postorder(root);
    return post;
  }
};