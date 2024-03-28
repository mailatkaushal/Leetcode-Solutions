// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> res;
  void left(Node* root) {
    if (root == NULL)
      return;
    if (root->left) {
      res.push_back(root->data);
      left(root->left);
    }
    else if (root->right) {
      res.push_back(root->data);
      left(root->right);
    }
  }
  void leaves(Node* root) {
    if (root == NULL)
      return;
    if (root->left == NULL && root->right == NULL) {
      res.push_back(root->data);
      return;
    }
    leaves(root->left);
    leaves(root->right);
  }
  void right(Node* root) {
    if (root == NULL)
        return;
    if (root->right) {
      right(root->right);
      res.push_back(root->data);
    }
    else if (root->left) {
      right(root->left);
      res.push_back(root->data);
    }
  }
  vector<int> boundary(Node* root) {
    res.push_back(root->data);
    left(root->left);
    leaves(root->left);
    leaves(root->right);
    right(root->right);
    return res;
  }
};