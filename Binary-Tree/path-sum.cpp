// Time  : O(n)
// Space : O(h)
bool hasPathSum(TreeNode* root, int targetSum) {
  if (root==NULL) return 0;
  targetSum-=root->val;
  if (root->left==NULL && root->right==NULL && targetSum==0) return 1;
  return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
}