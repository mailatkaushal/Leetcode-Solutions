// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    if (root == nullptr)
      return {};

    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      int ma = INT_MIN;

      while (n--) {
        TreeNode* node = q.front();
        q.pop();

        ma = max(ma, node->val);

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }

      res.push_back(ma);
    }

    return res;
  }
};