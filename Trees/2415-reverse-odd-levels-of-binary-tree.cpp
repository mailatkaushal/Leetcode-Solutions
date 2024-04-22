// Time  : O(n)
// Space : O(n)
class Solution {
public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int d = 0;
    while (!q.empty()) {
      int n = q.size();
      vector<TreeNode*> v;
      for (int i = 0; i < n; ++i) {
        auto x = q.front();
        q.pop();
        if (d % 2 == 1) v.push_back(x);
        if (x->left) q.push(x->left);
        if (x->right) q.push(x->right);
      }
      if (d % 2 == 1) {
        for (int i = 0; i < n / 2; ++i) {
          swap(v[i]->val, v[n-1-i]->val);
        }
      }
      ++d;
    }
    return root;
  }
};