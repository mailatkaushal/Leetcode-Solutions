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