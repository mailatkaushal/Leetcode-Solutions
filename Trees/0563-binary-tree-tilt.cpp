// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int f(TreeNode* root, int& sum) {
    if (root == NULL) return 0;
    int l = f(root->left, sum);
    int r = f(root->right, sum);
    sum += abs(l - r);
    return l + r + root->val;
  } 
  int findTilt(TreeNode* root) {
    int sum = 0;
    f(root, sum);
    return sum;
  }
};