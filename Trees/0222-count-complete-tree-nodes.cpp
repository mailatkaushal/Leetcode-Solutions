// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int countNodes(TreeNode* root) {
    if (root == NULL)
      return 0;
    int cnt = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      ++cnt;
      TreeNode* x = q.front();
      q.pop();
      if (x->left) 
        q.push(x->left);
      if (x->right)
        q.push(x->right);
    }
    return cnt;
  }
};

// Time  : O((logn)^2)
// Space : O(h)

class Solution {
public:
  int countNodes(TreeNode* root) {
    if (root == NULL)
      return 0;
    return f(root);
  }
  int f(TreeNode* root) {
    int lh = leftHeight(root);
    int rh = rightHeight(root);
    if (lh == rh) 
      return (1<<lh)-1;
    return 1 + f(root->left) + f(root->right);
  }
  int leftHeight(TreeNode* root) {
    int h = 0;
    while (root) {
      ++h;
      root = root->left;
    }
    return h;
  }
  int rightHeight(TreeNode* root) {
    int h = 0;
    while (root) {
      ++h;
      root = root->right;
    }
    return h;
  }
};