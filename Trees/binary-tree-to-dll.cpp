// Time  : O(n)
// Space : O(h)
class Solution {
public: 
  Node* prev;
  void dfs(Node* root) {
    if (root == NULL) return;
    dfs(root->left);
    prev->right = root;
    root->left = prev;
    prev = root;
    dfs(root->right);
  }
  //Function to convert binary tree to doubly linked list and return it.
  Node* bToDLL(Node* root) {
    Node* dummy = new Node(0);
    prev = dummy;
    dfs(root);
    Node* head = dummy->right;
    head->left = NULL;
    return head;
  }
};