// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> diagonalSum(Node* root) {
    vector<int> res;
    queue<Node*> q;
    q.push(root);
    while (q.size()) {
      int n = q.size();
      int sum = 0;
      while (n--) {
        Node* node = q.front();
        q.pop();
        while (node != NULL) {
          sum += node->data;
          if (node->left) q.push(node->left);
          node = node->right;
        }
      }
      res.push_back(sum);
    }
    return res;
  }
};

// Time  : O(n)
// Space : O(h+d) - Where h -> height of tree, d -> number of diagonals

class Solution {
public:
  map<int, int> ump;
  void dfs(Node* root, int d) {
    if (root == NULL) return;
    ump[d] += root->data;
    dfs(root->right, d);
    dfs(root->left, d+1);
  }
  vector<int> diagonalSum(Node* root) {
    dfs(root, 0);
    vector<int> res;
    for (auto it = ump.begin(); it != ump.end(); ++it)
      res.push_back(it->second);
    return res;
  }
};