// Time  : O(n)
// Space : O(n)

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return root;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode* node = st.top();
      st.pop();
      TreeNode* left = node->left;
      node->left = node->right;
      node->right = left;
      if (node->left) st.push(node->left);
      if (node->right) st.push(node->right);
    } 
    return root;
  }
};

// Time  : O(n)
// Space : O(h)

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return root;
    TreeNode* left = root->left;
    root->left = root->right;
    root->right = left;
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};