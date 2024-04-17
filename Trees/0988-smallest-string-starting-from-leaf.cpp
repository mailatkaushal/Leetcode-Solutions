// Time  : O(n*h)
// Space : O(h)
class Solution {
public:
  string ans = "";
  void dfs(TreeNode* x, string& s) {
    if (x == NULL) return;
    s += (x->val + 'a');
    if (x->left == NULL && x->right == NULL) {
      reverse(s.begin(), s.end());
      if (ans == "" || ans > s) ans = s;
      reverse(s.begin(), s.end());
    }
    dfs(x->left, s);
    dfs(x->right, s);
    s.pop_back();
  }
  string smallestFromLeaf(TreeNode* root) {
    string s;
    dfs(root, s);
    return ans;
  }
};

// Time  : O(n*h)
// Space : O(n)
class Solution {
public:
  string smallestFromLeaf(TreeNode* root) {
    string ans = "";
    queue<pair<TreeNode*, string>> q;
    q.push({root, string(1, root->val + 'a')});
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      TreeNode* x = p.first;
      string s = p.second;
      if (x->left == NULL && x->right == NULL) {
        reverse(s.begin(), s.end());
        if (ans == "" || ans > s) ans = s;
        continue;
      }
      if (x->left) q.push({x->left, s + char(x->left->val + 'a')});
      if (x->right) q.push({x->right, s + char(x->right->val + 'a')});
    }
    return ans;
  }
};