// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> r;
    if (root == NULL)
      return r;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        TreeNode* node = q.front();
        q.pop();
        if (i == n-1) 
          r.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }
    return r;
  }
};

// Time  : O(n)
// Space : O(h)

class Solution {
public:
  vector<int> r;
  void f(TreeNode* root, int d) {
    if (root == NULL) return;
    if (r.size() < d) r.push_back(root->val);
    f(root->right, d+1);
    f(root->left, d+1);
  }
  vector<int> rightSideView(TreeNode* root) {
    f(root, 1);
    return r;
  }
};