// Time  : O(logn*logn)
// Space : O(h)
int countNodes(TreeNode* root) {
    if (root==NULL) return 0;
    return f(root);
}
int f(TreeNode* root) {
    int lh=leftHeight(root);
    int rh=rightHeight(root);
    if (lh==rh) return (1<<lh)-1;
    return 1+f(root->left)+f(root->right);
}
int leftHeight(TreeNode* root) {
    int ans=0;
    while (root) {
        ans++;
        root=root->left;
    }
    return ans;
}
int rightHeight(TreeNode* root) {
    int ans=0;
    while (root) {
        ans++;
        root=root->right;
    }
    return ans;
}