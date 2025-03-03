// Time  : O(n)
// Space : O(n)
unordered_map<int,int> inMap;
TreeNode* f(vector<int>& inorder, int inStart, int inEnd, vector<int>& preorder, int preStart, int preEnd) {
    if (inStart>inEnd) return NULL;
    auto root=new TreeNode(preorder[preStart]);
    int i=inMap[root->val];
    int left=i-inStart;
    root->left=f(inorder,inStart,i-1,preorder,preStart+1,preStart+left);
    root->right=f(inorder,i+1,inEnd,preorder,preStart+left+1,preEnd);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n=preorder.size();
    for (int x=0; x<n; ++x) inMap[inorder[x]]=x;
    return f(inorder,0,n-1,preorder,0,n-1);
}