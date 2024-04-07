// Time  : O(logn)
// Space : O(logn)

class Solution {
public:
  int kthCommonAncestor(Node *root, int k,int x, int y) {
    vector<int> path;
    while (root) {
      path.push_back(root->data);
      if (root->data < x && root->data < y) root = root->right;
      else if (root->data > x && root->data > y) root = root->left;
      else break;
    }
    int n = path.size();
    return k > n ? -1 : path[n-k];
  }
};