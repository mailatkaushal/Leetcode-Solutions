// Time  : O(n)
// Space : O(n)

class Solution {
public: 
  Node* bToDLL(Node* root) {
    vector<int> v;
    while (root) {
      if (root->left == NULL) {
        v.push_back(root->data);
        root = root->right;
      }
      else {
        Node* prev = root->left;
        while (prev->right)
          prev = prev->right;
        prev->right = root;
        Node* tmp = root;
        root = root->left;
        tmp->left = NULL;
      }
    }
    Node* head = NULL;
    Node* prev = NULL;
    for (int i = 0; i < v.size(); ++i) {
      Node* curr = new Node(v[i]);
      if (i == 0) head = curr;
      curr->left = prev;
      if (prev) prev->right = curr;
      prev = curr;
    }
    return head;
  }
};