// Time  : O(logn)
// Space : O(1)

int findCeil(Node* root, int x) {
  if (root == NULL) return -1;
  int c = -1;
  while (root) {
    if (root->data == x) 
      return x;
    else if (root->data < x) 
      root = root->right;
    else {
      c = root->data;
      root = root->left;
    }
  }
  return c;
}