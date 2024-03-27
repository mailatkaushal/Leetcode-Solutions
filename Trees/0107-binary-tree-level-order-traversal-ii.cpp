// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL)
      return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> tmp;
      int n = q.size();
      while (n--) {
        TreeNode* node = q.front();
        q.pop();
        tmp.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      res.insert(res.begin(), tmp);
    }
    return res;
  }
};