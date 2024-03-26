// Time  : O(n)
// Space : O(h)

class Solution {
public:
  vector<int> in;
  void inorder(TreeNode*& root) {
    if (root == NULL) 
      return;
    inorder(root->left);
    in.push_back(root->val);
    inorder(root->right);
  }
  vector<int> inorderTraversal(TreeNode* root) {
    inorder(root);
    return in;
  }
};

// Time  : O(n)
// Space : O(n)

class Solution { 
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> in;
    stack<TreeNode*> stk;
    while (root || !stk.empty()) {
      while (root) {
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      in.push_back(root->val);
      root = root->right;
    }
    return in;
  }
};

// Morris Traversal
// Time  : O(n)
// Space : O(1)

class Solution { 
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> in;
    TreeNode* curr = root;
    while (curr) {
      if (curr->left == NULL) {
        in.push_back(curr->val);
        curr = curr->right;
      }
      else {
        TreeNode* prev = curr->left;
        while (prev->right)
          prev = prev->right;
        prev->right = curr;
        TreeNode* tmp = curr;
        curr = curr->left;
        tmp->left = NULL;
      }
    }
    return in;
  }
};