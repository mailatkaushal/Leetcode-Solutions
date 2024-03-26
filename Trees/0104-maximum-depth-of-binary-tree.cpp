// Time  : O(n)
// Space : O(h)

class Solution {
public:
  int max_lvl = 0;
  void dfs(TreeNode* root, int lvl) {
    if (root == NULL)
      return;
    if (root->left == NULL && root->right == NULL) 
      max_lvl = max(max_lvl, lvl);
    dfs(root->left, lvl+1);
    dfs(root->right, lvl+1);
  }
  int maxDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;
    dfs(root, 1);
    return max_lvl;
  }
};

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