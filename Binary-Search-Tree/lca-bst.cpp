TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val<root->val && q->val<root->val) root=root->left;
        else if (root->val<p->val && root->val<q->val) root=root->right;
        else break;
    }
    return root;
}