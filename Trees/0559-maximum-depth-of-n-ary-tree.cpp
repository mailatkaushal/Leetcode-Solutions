// Time  : O(n)
// Space : O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int d = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      ++d;
      int n = q.size();
      while (n--) {
        Node* node = q.front();
        q.pop();
        int x = node->children.size();
        for (int i = 0; i < x; ++i) 
          if (node->children[i] != NULL) q.push(node->children[i]);
      }
    }
    return d;
  }
};