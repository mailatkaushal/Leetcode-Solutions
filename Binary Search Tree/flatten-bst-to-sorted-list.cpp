// Time  : O(n)
// Space : O(1)

class Solution {
public:
  Node* flattenBST(Node* root) {
    Node* dummy = new Node(0);
    Node* x = dummy;
    while (root) {
      if (root->left == NULL) {
        x->right = new Node(root->data);
        x = x->right;
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
    return dummy->right;
  }
};