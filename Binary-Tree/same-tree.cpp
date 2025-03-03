// Time  : O(n)
// Space : O(h)
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p==NULL && q==NULL) return 1;
    if (p==NULL || q==NULL) return 0;
    return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

// Time  : O(n)
// Space : O(n)
bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<TreeNode*> q1,q2;
    q1.push(p);
    q2.push(q);
    while (!q1.empty() && !q2.empty()) {
        auto x=q1.front();
        q1.pop();
        auto y=q2.front();
        q2.pop();
        if (x==NULL && y==NULL) continue;
        else if (x==NULL || y==NULL || x->val!=y->val) return 0;
        q1.push(x->left);
        q1.push(x->right);
        q2.push(y->left);
        q2.push(y->right);
    }
    return 1;
}