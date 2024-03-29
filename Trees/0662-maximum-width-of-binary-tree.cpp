// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int widthOfBinaryTree(TreeNode* root) {
    long long wid = 0;
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    while (!q.empty()) {
      long long n = q.size();
      long long x = q.front().second;
      long long y = q.back().second;
      wid = max(wid, y - x + 1);
      for (int i = 0; i < n; ++i) {
        auto p = q.front();
        q.pop();
        long long idx = p.second - x;
        if (p.first->left)
          q.push({p.first->left, 2 * idx + 1});
        if (p.first->right)
          q.push({p.first->right, 2 * idx + 2});
      } 
    }
    return wid;
  }
};