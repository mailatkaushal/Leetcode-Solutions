// Time  : O(n)
// Space : O(n)
void flatten(TreeNode* root) {
  if (root==NULL) return;
  stack<TreeNode*> st;
  st.push(root);
  while (!st.empty()) {
      auto x=st.top();
      st.pop();
      if (x->right) st.push(x->right);
      if (x->left) st.push(x->left);
      if (!st.empty()) x->right=st.top();
      x->left=NULL;
  }
}

// Time  : O(n)
// Space : O(h)
// Reverse Postorder
TreeNode* pre=NULL;
void flatten(TreeNode* root) {
    if (root==NULL) return;
    flatten(root->right);
    flatten(root->left);
    root->right=pre;
    root->left=NULL;
    pre=root;
}

// Time  : O(n)
// Space : O(1)
// Morris Traversal
void flatten(TreeNode* root) {
    while (root) {
        if (root->left) {
            auto x=root->left;
            while (x->right) x=x->right;
            x->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        root=root->right;
    }
}