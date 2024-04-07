// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int rangeSumBST(TreeNode* root, int lo, int hi) {
    int x = 0;
    while (root) {
      if (root->left == NULL) {
        if (lo <= root->val && root->val <= hi) x += root->val;
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
    return x;
  }
};

// Time  : O(n)
// Space : O(h)

class Solution {
public:
  int rangeSumBST(TreeNode* root, int& lo, int& hi) {
    if (root == NULL) return 0;
    if (lo <= root->val && root->val <= hi) 
      return root->val + rangeSumBST(root->left, lo, hi) + rangeSumBST(root->right, lo, hi);
    if (root->val < lo) 
      return rangeSumBST(root->right, lo, hi);
    return rangeSumBST(root->left, lo, hi);
  }
};