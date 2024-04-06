// Time  : O(n)
// Space : O(n)

class Solution {
public:
  bool isCompleteTree(TreeNode* root) {
    bool flag = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (node == NULL) flag = true;
      else {
        if (flag) return false;
        q.push(node->left);
        q.push(node->right);
      }
    }
    return true;
  }
};