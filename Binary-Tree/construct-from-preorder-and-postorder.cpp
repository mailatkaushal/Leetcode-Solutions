unordered_map<int,int> mp;
TreeNode* f(int preStart, int preEnd, int postStart,vector<int>& preorder, vector<int>& postorder) {
    if (preStart>preEnd) return NULL;
    auto root=new TreeNode(preorder[preStart]);
    if (preStart==preEnd) return root;
    int i=mp[preorder[preStart+1]];
    // while (postorder[i]!=preorder[preStart+1]) ++i;
    int x=i-postStart+1;
    root->left=f(preStart+1,preStart+x,postStart,preorder,postorder);
    root->right=f(preStart+x+1,preEnd,i+1,preorder,postorder);
    return root;
}
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    for (int i=0; i<postorder.size(); ++i) mp[postorder[i]]=i;
    return f(0, preorder.size()-1, 0, preorder, postorder);
}