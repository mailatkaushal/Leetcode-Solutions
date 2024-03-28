// Time  : O(n)
// Space : O(n)

Node* createTree(vector<int>& A){
  Node* root = new Node(A[0]);
  queue<Node*> q;
  q.push(root);
  int i = 1;
  while (i < A.size()) {
    Node* root = q.front();
    q.pop();
    if (A[i] != -1) {
      Node* l = new Node(A[i]);
      root->left = l;
      q.push(l);
    }
    ++i;
    if (i < A.size() && A[i] != -1) {
      Node* r = new Node(A[i]);
      root->right = r;
      q.push(r);
    }
    ++i;
  }
  return root;
}