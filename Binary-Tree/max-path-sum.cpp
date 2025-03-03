// Time  : O(n)
// Space : O(h)
int ans=INT_MIN;
int f(TreeNode* root) {
    if (root==NULL) return 0;
    int l=f(root->left);
    int r=f(root->right);
    ans=max({ans,root->val,l+root->val,r+root->val,l+r+root->val});
    return max({root->val,l+root->val,r+root->val});
}
int maxPathSum(TreeNode* root) {
    f(root);
    return ans;
}