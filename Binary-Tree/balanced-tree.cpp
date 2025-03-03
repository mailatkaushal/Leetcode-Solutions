// Time  : O(n)
// Space : O(h)
pair<bool,int> f(TreeNode* root) {
  if (root==NULL) return {1,0};
  auto l=f(root->left);
  auto r=f(root->right);
  bool balanced=l.first && r.first && abs(l.second-r.second)<=1;
  int height=1+max(l.second,r.second);
  return {balanced,height};
}
bool isBalanced(TreeNode* root) {
  auto p=f(root);
  return p.first;
}