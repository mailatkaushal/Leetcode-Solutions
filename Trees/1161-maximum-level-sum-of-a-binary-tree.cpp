// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int maxLevelSum(TreeNode* root) {
    int d = 0;
    int ma = 0;
    int maxsum = -100001;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      ++d;
      int sum = 0;
      int n = q.size();
      while (n--) {
        TreeNode* node = q.front();
        q.pop();
        sum += node->val;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      if (sum > maxsum) {
        maxsum = sum;
        ma = d;
      }
    }
    return ma;
  }
};