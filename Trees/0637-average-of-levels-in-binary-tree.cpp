// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      long sum = 0;
      for (int i = 0; i < n; ++i) {
        TreeNode* node = q.front();
        q.pop();
        sum += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      res.push_back((double)sum/n);
    }

    return res;
  }
};