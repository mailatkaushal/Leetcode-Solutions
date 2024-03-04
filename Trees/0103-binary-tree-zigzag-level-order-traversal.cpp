// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    int level = -1;

    while (!q.empty()) {
      ++level;
      int n = q.size();
      vector<int> tmp;

      while (n--) {
        TreeNode* node = q.front();
        q.pop();

        if ((level & 1) == 0)
          tmp.push_back(node->val);
        else 
          tmp.insert(tmp.begin(), node->val);

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }

      res.push_back(tmp);
    }

    return res;
  }
};