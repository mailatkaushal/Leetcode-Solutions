class Solution {
public:
  // function should print the nodes at k distance from root
  vector<int> Kdistance(struct Node* root, int k) {
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    int d = 0;
    while (!q.empty()) {
      int z = q.size();
      while (z--) {
        Node* x = q.front();
        q.pop();
        if (d == k) {
          ans.push_back(x->data);
          continue;
        }
        if (x->left) q.push(x->left);
        if (x->right) q.push(x->right);
      }
      ++d;
    }
    return ans;
  }
};