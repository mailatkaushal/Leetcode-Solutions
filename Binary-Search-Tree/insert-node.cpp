// Time  : O(logn)
TreeNode* insertIntoBST(TreeNode* root, int key) {
    if (root==NULL) return new TreeNode(key);
    TreeNode* x=root;
    while (x) {
        if (key<x->val) {
            if (x->left) x=x->left;
            else { x->left=new TreeNode(key); break; }
        }
        else {
            if (x->right) x=x->right;
            else { x->right=new TreeNode(key); break; }
        }
    }
    return root;
}