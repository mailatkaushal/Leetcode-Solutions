// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int minDiffInBST(TreeNode* root) {
    int pre = -1;
    int mi = 1e5;
    while (root) {
      if (root->left == NULL) {
        if (pre != -1) 
          mi = min(mi, root->val - pre);
        pre = root->val;
        root = root->right;
      }
      else {
        TreeNode* prev = root->left;
        while (prev->right)
          prev = prev->right;
        prev->right = root;
        TreeNode* tmp = root;
        root = root->left;
        tmp->left = NULL;
      }
    }
    return mi;
  }
};