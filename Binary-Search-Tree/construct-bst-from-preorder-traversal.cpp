// Time  : O(n)
// Space : O(h)
TreeNode* bstFromPreorder(vector<int>& preorder) {
  int i=0;
  return f(preorder,i,1000);
}
TreeNode* f(vector<int>& preorder, int& i, int ub) {
  if (i==preorder.size() || preorder[i]>ub) return NULL;
  TreeNode* root=new TreeNode(preorder[i++]);
  root->left=f(preorder,i,root->val);
  root->right=f(preorder,i,ub);
  return root;
}