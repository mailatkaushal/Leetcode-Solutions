class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;

  void f(TreeNode* root, int k) {
    if (!root)
      return;

    path.push_back(root->val);

    if (!root->left && !root->right && k == root->val) 
      res.push_back(path);

    f(root->left, k - root->val);
    f(root->right, k - root->val);

    path.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    f(root, targetSum);
    return res;
  }
};