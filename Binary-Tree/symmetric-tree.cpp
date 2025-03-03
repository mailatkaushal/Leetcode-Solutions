// Time  : O(n)
// Space : O(h)
bool f(TreeNode* p, TreeNode* q) {
    if (p==NULL && q==NULL) return 1;
    if (p==NULL || q==NULL) return 0;
    return p->val==q->val && f(p->left,q->right) && f(p->right,q->left);
}
bool isSymmetric(TreeNode* root) {
    return f(root->left,root->right);
}

// Time  : O(n)
// Space : O(n)
bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty()) {
        auto x=q.front(); 
        q.pop();
        auto y=q.front();
        q.pop();
        if (x==NULL && y==NULL) continue;
        else if (x==NULL || y==NULL || x->val!=y->val) return 0;
        q.push(x->left); 
        q.push(y->right); 
        q.push(x->right); 
        q.push(y->left); 
    }
    return 1;
}