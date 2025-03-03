// Time  : O(n)
// Space : O(h)
TreeNode* invertTree(TreeNode* root) {
    if (root==NULL) return NULL;
    auto tmp=root->left;
    root->left=root->right;
    root->right=tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// Time  : O(n)
// Space : O(n)
TreeNode* invertTree(TreeNode* root) {
    if (root==NULL) return NULL;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto x=q.front();
        q.pop();
        auto tmp=x->left;
        x->left=x->right;
        x->right=tmp;
        if (x->right) q.push(x->right);
        if (x->left) q.push(x->left);
    }
    return root;
}