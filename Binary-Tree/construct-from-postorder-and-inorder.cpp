// Time  : O(n)
// Space : O(n)
unordered_map<int,int> inMap;
TreeNode* f(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
    if (inStart>inEnd) return NULL;
    auto root=new TreeNode(postorder[postEnd]);
    int i=inMap[root->val];
    int left=i-inStart;
    root->left=f(inorder,inStart,i-1,postorder,postStart,postStart+left-1);
    root->right=f(inorder,i+1,inEnd,postorder,postStart+left,postEnd-1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n=inorder.size();
    for (int x=0; x<n; ++x) inMap[inorder[x]]=x;
    return f(inorder,0,n-1,postorder,0,n-1);
}