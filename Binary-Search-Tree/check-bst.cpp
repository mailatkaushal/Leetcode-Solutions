// Time  : O(n)
bool isValidBST(TreeNode* root) {
    long long p=LLONG_MIN;
    TreeNode* x=root;
    while (x) {
        if (x->left==NULL) {
            if (p>=x->val) return 0;
            p=x->val;
            x=x->right;
        }
        else {
            TreeNode* y=x->left;
            while (y->right) y=y->right;
            y->right=x;
            TreeNode* z=x;
            x=x->left;
            z->left=NULL;
        }
    }
    return 1;
}