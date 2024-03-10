// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      vector<int> level(n);
      int x = 0;
      while (n--) {
        TreeNode* node = q.front();
        q.pop();
        level[x++] = node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      res.push_back(level);
    }

    return res;
  }
};