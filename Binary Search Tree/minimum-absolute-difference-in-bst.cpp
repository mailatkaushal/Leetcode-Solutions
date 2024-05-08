// Time  : O(n)
// Time  : O(1)
class Solution {
public:
  int absolute_diff(Node* x) {
    int ans = 1e9;
    int i = 0;
    int p;
    while (x) {
      if (x->left == NULL) {
        if (i > 0) ans = min(ans, abs(x->data - p));
        i++;
        p = x->data;
        x = x->right;
      }
      else {
        Node* y = x->left;
        while (y->right) y = y->right;
        y->right = x;
        Node* z = x;
        x = x->left;
        z->left = NULL;
      }
    }
    return ans;
  }
};