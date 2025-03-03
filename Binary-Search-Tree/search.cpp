// Time  : O(logn)
TreeNode* searchBST(TreeNode* root, int x) {
    while (root) {
        if (root->val==x) break;
        if (root->val<x) root=root->right;
        else root=root->left;
    }
    return root;
}