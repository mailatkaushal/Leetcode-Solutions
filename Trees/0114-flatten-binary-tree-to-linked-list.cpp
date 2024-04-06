// Time  : O(n)
// Space : O(n)

class Solution {
public:
  void flatten(TreeNode* root) {
    if (root == NULL) return;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode* node = st.top();
      st.pop();
      if (node->right) 
        st.push(node->right);
      if (node->left) 
        st.push(node->left);
      if (!st.empty())
        node->right = st.top();
      node->left = NULL;
    } 
  }
};

// Time  : O(n)
// Space : O(1)
// Morris Traversal

class Solution {
public:
  void flatten(TreeNode* root) {
    while (root) {
      if (root->left) {
        TreeNode* prev = root->left;
        while (prev->right)
          prev = prev->right;
        prev->right = root->right;
        root->right = root->left;
        root->left = NULL;
      }
      root = root->right;
    }
  }
};