// Time  : O(n)
// Space : O(1)
class Solution {
public:
  int kthLargest(Node* x, int k) {
    int i = 0;
    int ans;
    while (x) {
      if (x->right == NULL) {
        if (++i == k) { ans = x->data; break; }
        x = x->left;
      }
      else {
        Node* y = x->right;
        while (y->left) y = y->left;
        y->left = x;
        Node* z = x;
        x = x->right;
        z->right = NULL;
      }
    }
    return ans;
  }
};