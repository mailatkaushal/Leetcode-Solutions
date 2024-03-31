// Time  : O(logn)
// Space : O(logn)

class Solution {
public:
  TreeNode* searchBST(TreeNode* root, int x) {
    if (root == NULL || root->val == x)
      return root;
    if (root->val < x) 
      return searchBST(root->right, x);
    return searchBST(root->left, x);
  }
};

// Time  : O(logn)
// Space : O(1)

class Solution {
public:
  TreeNode* searchBST(TreeNode* root, int x) {
    while (root != NULL && root->val != x) {
      if (root->val < x)
        root = root->right;
      else
        root = root->left;
    }
    return root;
  }
};