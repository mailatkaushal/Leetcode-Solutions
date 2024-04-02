// Time  : O(n)
// Time  : O(1)

class Solution {
public:
  int absolute_diff(Node *root) {
    int mi = 1e9;
    int i = 0;
    int prev_val;
    while (root) {
      if (root->left == NULL) {
        if (i > 0) {
          mi = min(mi, abs(prev_val - root->data));
        }
        ++i;
        prev_val = root->data;
        root = root->right;
      }
      else {
        Node* pre = root->left;
        while (pre->right) 
          pre = pre->right;
        pre->right = root;
        Node* tmp = root;
        root = root->left;
        tmp->left = NULL;
      }
    }
    return mi;
  }
};