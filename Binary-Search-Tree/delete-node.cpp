// Time  : O(logn)
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root==NULL) return NULL;
    if (root->val==key) return f(root);
    TreeNode* x=root;
    while (x) {
        if (key<x->val) {
            if (x->left && x->left->val==key) { x->left=f(x->left); break; }
            else x=x->left;
        }
        else {
            if (x->right && x->right->val==key) { x->right=f(x->right); break; }
            else x=x->right; 
        }
    }
    return root;
}
TreeNode* f(TreeNode* del) {
    if (del->left==NULL) return del->right;
    if (del->right==NULL) return del->left;
    TreeNode* rightLeftMost=del->right;
    while (rightLeftMost->left) rightLeftMost=rightLeftMost->left;
    rightLeftMost->left=del->left;
    return del->right;
}