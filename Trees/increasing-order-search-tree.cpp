// Time  : O(n)
// Space : O(n)

class Solution {
public:
  TreeNode* increasingBST(TreeNode* root) {
    vector<int> v;
    while (root) {
      if (root->left == NULL) {
        v.push_back(root->val);
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
    TreeNode* dummy = new TreeNode();
    TreeNode* x = dummy;
    for (int i = 0; i < v.size(); ++i) {
      x->right = new TreeNode(v[i]);
      x = x->right;
    }
    return dummy->right;
  }
};