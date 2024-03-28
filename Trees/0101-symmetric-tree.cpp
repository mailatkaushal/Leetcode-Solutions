// Time  : O(n)
// Space : O(h)

class Solution {
public:
  bool f(TreeNode* a, TreeNode* b) {
    if (a == NULL && b == NULL)
      return true;
    if (a == NULL || b == NULL)
      return false;
    return a->val == b->val && f(a->left, b->right) && f(a->right, b->left);
  }
  bool isSymmetric(TreeNode* root) {
    return f(root->left, root->right);
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty()) {
      TreeNode* a = q.front();
      q.pop();
      TreeNode* b = q.front();
      q.pop();
      if (a == NULL && b == NULL) continue;
      if (a == NULL || b == NULL) return false;
      if (a->val != b->val) return false;
      q.push(a->left);
      q.push(b->right);
      q.push(a->right);
      q.push(b->left);
    }
    return true;
  }
};