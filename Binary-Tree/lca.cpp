// Time  : O(n)
// Space : O(h)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root==NULL || root==p || root==q) return root;
    TreeNode* l=lowestCommonAncestor(root->left,p,q);
    TreeNode* r=lowestCommonAncestor(root->right,p,q);
    if (l==NULL) return r;
    if (r==NULL) return l;
    return root;
}