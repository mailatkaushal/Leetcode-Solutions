// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int maxDepth(TreeNode* root) {
    int ma = 0;
    if (root == NULL)
      return ma;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      ++ma;
      int n = q.size();
      while (n--) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }
    return ma;
  }
};