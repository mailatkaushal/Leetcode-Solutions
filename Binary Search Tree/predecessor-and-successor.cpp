// Time  : O(logn)
// Spaec : O(1)

class Solution {
public:
  void findPreSuc(Node* root, Node*& pre, Node*& suc, int x) {
    Node* i = root;
    while (i) {
      if (i->key < x) {
        pre = i;
        i = i->right;
      }
      else 
        i = i->left;
    }
    i = root;
    while (i) {
      if (i->key <= x)
        i = i->right;
      else {
        suc = i;
        i = i->left;
      }
    }
  }
};