// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int getMinimumDifference(TreeNode* root) {
    int x = -1;
    int mi = 1e5;
    while (root) {
      if (root->left == NULL) {
        if (x != -1)
          mi = min(mi, root->val - x);
        x = root->val;
        root = root->right;
      }
      else {
        TreeNode* pre = root->left;
        while (pre->right)
          pre = pre->right;
        pre->right = root;
        TreeNode* tmp = root;
        root = root->left;
        tmp->left = NULL;
      }
    }
    return mi;
  }
};