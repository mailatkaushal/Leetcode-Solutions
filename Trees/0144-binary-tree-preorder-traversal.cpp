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

// Morris Traversal
// Time  : O(n)
// Space : O(1)

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> pre;
    TreeNode* curr = root;
    while (curr) {
      if (curr->left == NULL) {
        pre.push_back(curr->val);
        curr = curr->right;
      } 
      else {
        TreeNode* prev = curr->left;
        while (prev->right && prev->right != curr) 
          prev = prev->right;
        if (prev->right == NULL) {
          prev->right = curr;
          pre.push_back(curr->val);
          curr = curr->left;
        }
        else {
          prev->right = NULL;
          curr = curr->right;
        }
      }
    }
    return pre;
  }
};