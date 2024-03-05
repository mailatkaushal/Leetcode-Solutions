// Time:  O(n)
// Space: O(n)

class Solution {
public:
  int minDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;

    queue<TreeNode*> q;
    q.push(root);
    int lvl = 0;

    while (!q.empty()) {
      ++lvl;
      int n = q.size();

      while (n--) {
        TreeNode* node = q.front();
        q.pop();

        if (!node->left && !node->right)
          return lvl;

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }

    return -1;
  }
};