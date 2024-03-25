// Time  : O(n)
// Space : O(n)

vector<int> levelOrder(TreeNode<int>* root) {
  if (root == NULL) 
    return {};
  vector<int> res;
  queue<TreeNode<int>*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode<int>* node = q.front();
    q.pop();
    res.push_back(node->data);
    if (node->left) 
      q.push(node->left);
    if (node->right)
      q.push(node->right);
  }
  return res;
}