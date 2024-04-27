// Time  : O(n)
// Space : O(n)
vector<int> diagonal(Node *root) {
  vector<int> res;
  queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    Node* node = q.front();
    q.pop();
    while (node) {
      res.push_back(node->data);
      if (node->left) q.push(node->left);
      node = node->right;
    }
  }
  return res;
}