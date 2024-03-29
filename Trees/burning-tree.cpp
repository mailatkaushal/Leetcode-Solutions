// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int minTime(Node* root, int target) {
    Node* targetNode = NULL;
    unordered_map<Node*, Node*> parent;  // node -> parent
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      Node* node = q.front();
      q.pop();
      if (targetNode == NULL && target == node->data) targetNode = node;
      if (node->left) {
        parent[node->left] = node;
        q.push(node->left);
      }
      if (node->right) {
        parent[node->right] = node;
        q.push(node->right);
      }
    }
    q.push(targetNode);
    unordered_set<Node*> visited;
    visited.insert(targetNode);
    int t = -1;
    while (!q.empty()) {
      ++t;
      int n = q.size();
      while (n--) {
        Node* node = q.front();
        q.pop();
        if (node->left && visited.find(node->left) == visited.end()) {
          q.push(node->left);
          visited.insert(node->left);
        }
        if (node->right && visited.find(node->right) == visited.end()) {
          q.push(node->right);
          visited.insert(node->right);
        }
        if (parent[node] && visited.find(parent[node]) == visited.end()) {
          q.push(parent[node]);
          visited.insert(parent[node]);
        }
      }
    }
    return t;
  }
};