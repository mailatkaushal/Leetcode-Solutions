// Time  : O(n^2)
// Space : O(1)

class Solution {
public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    for (int i = 1; i < preorder.size(); ++i) {
      TreeNode* cur = root;
      while (1) {
        if (cur->val < preorder[i]) {
          if (cur->right == NULL) {
            cur->right = new TreeNode(preorder[i]);
            break;
          }
          else cur = cur->right;
        }
        else {
          if (cur->left == NULL) {
            cur->left = new TreeNode(preorder[i]);
            break;
          }
          else cur = cur->left;
        }
      }
    }
    return root;
  }
};

// Time  : O(n)
// Space : O(h)

class Solution {
public:
  TreeNode* bstFromPreorder(vector<int>& A) {
    int i = 0;
    return build(A, i, 1001);
  }
  TreeNode* build(vector<int>& A, int& i, int ub) {
    if (i == A.size() || A[i] > ub) return NULL;
    TreeNode* root = new TreeNode(A[i++]);
    root->left = build(A, i, root->val);
    root->right = build(A, i, ub);
    return root;
  }
};