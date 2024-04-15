// Time  : O(2n + nlogn)
// Space : O(logn)
class Solution {
public:
  void recoverTree(TreeNode* root) {
    vector<int> A;
    TreeNode* cur = root;
    while (cur) {
      if (cur->left == NULL) {
        A.push_back(cur->val);
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
          A.push_back(cur->val);
          cur = cur->right;
        }
      }
    }
    sort(A.begin(), A.end());
    cur = root;
    int i = 0;
    while (cur) {
      if (cur->left == NULL) {
        cur->val = A[i++];
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
          cur->val = A[i++];
          cur = cur->right;
        }
      }
    }
  }
};