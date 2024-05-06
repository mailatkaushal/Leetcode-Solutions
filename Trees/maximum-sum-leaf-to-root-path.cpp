// Time  : O(n)
// Space : O(n)
class Solution{
public:
  int maxPathSum(Node* root) {
    int ans = INT_MIN;
    queue<pair<Node*, int>> q;
    q.push({root, root->data});
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      Node* x = p.first;
      int sum = p.second;
      if (x->left == NULL && x->right == NULL) {
        ans = max(ans, sum);
        continue;
      }
      if (x->left) q.push({x->left, sum + x->left->data});
      if (x->right) q.push({x->right, sum + x->right->data});
    }
    return ans;
  }
};