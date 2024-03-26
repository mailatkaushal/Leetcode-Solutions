// Time  : O(n)
// Space : O(h)

class Solution {
public:
  vector<int> pre;
  void preorder(TreeNode* root) {
    if (root == NULL)
      return;
    pre.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
  }
  vector<int> preorderTraversal(TreeNode* root) {
    preorder(root);
    return pre;
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> pre;
    if (root == NULL)
      return pre;
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode* root = stk.top();
      stk.pop();
      pre.push_back(root->val);
      if (root->right)
        stk.push(root->right);
      if (root->left)
        stk.push(root->left);
    }
    return pre;
  }
};