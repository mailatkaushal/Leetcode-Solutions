// Time  : O(n)
// Space : O(1)
class Solution {
public:
  void recoverTree(TreeNode* root) {
    TreeNode* p = NULL;
    TreeNode* x = NULL;
    TreeNode* y = NULL;
    TreeNode* cur = root;
    while (cur) {
      if (cur->left == NULL) {
        if (p && p->val > cur->val) {
          if (x == NULL) x = p;
          y = cur;
        }
        p = cur;
        cur = cur->right;
      }
      else {
        TreeNode* pre = cur->left;
        while (pre->right && pre->right != cur) 
          pre = pre->right;
        if (pre->right == NULL) {
          pre->right = cur;
          cur = cur->left;
        }
        else {
          pre->right = NULL;
          if (p && p->val > cur->val) {
            if (!x) x = p;
            y = cur; 
          }
          p = cur;
          cur = cur->right;
        }
      }
    }
    swap(x->val, y->val);
  }
};