// Time  : O(n)
// Space : O(h)
class Solution {
public:
  int sumNumbers(TreeNode* root, int sum = 0) {
    if (root == NULL) return 0;
    sum = sum*10 + root->val;
    if (root->left == NULL && root->right == NULL) return sum;
    int l = sumNumbers(root->left, sum);
    int r = sumNumbers(root->right, sum);
    return l + r;
  }
};

// Time  : O(n)
// Space : O(n)
class Solution {
public:
  int sumNumbers(TreeNode* root) {
    int sum = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, root->val});
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      TreeNode* x = p.first;
      int num = p.second;
      if (x->left == NULL && x->right == NULL) {
        sum += num;
        continue;
      }
      if (x->left) q.push({x->left, num * 10 + x->left->val});
      if (x->right) q.push({x->right, num * 10 + x->right->val});
    } 
    return sum;
  }
};