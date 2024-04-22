// Time  : O(n)
// Space : O(n)
class Solution {
public:
  int sumRootToLeaf(TreeNode* root) {
    int ans = 0;
    queue<pair<TreeNode*, string>> q;
    q.push({root, to_string(root->val)});
    while (!q.empty()) {
      auto [x, s] = q.front();
      q.pop();
      if (x->left == NULL && x->right == NULL) {
        int num = 0;
        int i = 0;
        while (!s.empty()) {
          bool bit = s.back() - '0';
          s.pop_back();
          if (bit) num += pow(2, i);
          ++i; 
        }
        ans += num;
        continue;
      }
      if (x->left) q.push({x->left, s + to_string(x->left->val)});
      if (x->right) q.push({x->right, s + to_string(x->right->val)});
    }
    return ans;
  }
};