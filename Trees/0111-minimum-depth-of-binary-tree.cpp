// DFS
// Time:  O(n)
// Space: O(h)

class Solution {
public:
  int min_lvl = INT_MAX;

  void dfs(TreeNode* root, int lvl) {
    if (root == nullptr)
      return;
    if (root->left == nullptr && root->right == nullptr)
      min_lvl = min(min_lvl, lvl);
    
    dfs(root->left, lvl+1);
    dfs(root->right, lvl+1);
  } 

  int minDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;
      
    dfs(root, 1);
    return min_lvl;
  }
};

// BFS
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