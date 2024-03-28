// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> zz;
    if (root == NULL)
      return zz;
    bool lr = false;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      lr = !lr;
      int n = q.size();
      vector<int> z(n);
      for (int i = 0; i < n; ++i) {
        TreeNode* node = q.front();
        q.pop();
        int idx = lr == true ? i : n - 1 - i;
        z[idx] = node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      zz.push_back(z);
    }
    return zz;
  }
};