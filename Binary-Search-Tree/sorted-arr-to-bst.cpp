TreeNode* f(vector<int>& A, int l, int r) {
    if (l>r) return NULL;
    int mid=(l+r)>>1;
    TreeNode* root=new TreeNode(A[mid]);
    root->left=f(A,l,mid-1);
    root->right=f(A,mid+1,r);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& A) {
    return f(A,0,A.size()-1);
}