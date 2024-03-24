// Time  : O(n)
// Space : O(h)

class Solution {
public:
  int max_sum = 0;
  int max_len = 0;
  void dfs(Node* node, int sum, int len) {
    if (node == nullptr)
      return;
    sum += node->data;
    ++len;
    if (!node->left && !node->right) {
      if (len > max_len) {
        max_len = len;
        max_sum = sum;
      }
      else if (len == max_len) 
        max_sum = max(max_sum, sum);
    }
    dfs(node->left, sum, len);
    dfs(node->right, sum, len);
  }
  int sumOfLongRootToLeafPath(Node* root) {
    dfs(root, 0, 0);
    return max_sum;
  }
};